#include<iostream> 
#include<vector> 

using namespace std;

bool searchInRow(vector<vector<int>>& matrix, int target, int row){
    int n= matrix[0].size();  //no. of columns
    int st=0, end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if (target== matrix[row][mid]){
            return true;
        }else if(target > matrix[row][mid]){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}


bool search(vector<vector<int>>& matrix, int target){
    //BS on total no. of rows:
    int m=matrix.size(), n=matrix[0].size();
    //m= no. of rows && n= no.of columns 
    int startrow=0, endrow=m-1;
    while (startrow<=endrow){
        int midrow= startrow+(endrow-startrow)/2;
        if (target>=matrix[midrow][0] && target<=matrix[midrow][n-1]){
            return searchInRow(matrix,target, midrow);
        }else if (target>=matrix[midrow][n-1])
        {
            startrow=midrow+1;  //down => right
        }else{
            endrow=midrow-1;    //up=> left 
        }
    }
    return false;
}

//2. search in 2d matrix II
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size(),n=mat[0].size();
    int r=m-1, c=0; //taking for mid condition which one to choose
    while(r>=0 && c<n){
        if(target ==mat[r][c]){
            return true;
        }else if(target<mat[r][c]){
            r--;
        }
        else{
            c++;
        }
    }
    return false;
}

int main(){

    //LC_74: Search In a 2D matrix
    //bruteforce: 0(n*m)
    //binary search approach: 0(log(n*m))
    
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 34;
    bool sol= search(matrix,target);
    cout<<sol;

    //LC_240: Search in a 2D Matrix II
    vector<vector<int>> mat={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int targ=5;

    bool solII= searchMatrix(mat,targ);
    cout<<solII;




    return 0;
}