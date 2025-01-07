#include<iostream>
#include<algorithm>
using namespace std;

bool linearSearch(int matrix[][3], int rows, int cols, int key){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j]==key)
            {
                return 1;
            }
        }
    }
    return false;
}

int getMaxSum(int matrix[][2], int rows, int cols){
    int maxRowSum=INT16_MIN;

    for (int i = 0; i < rows; i++){
        int rowSum=0;
        for (int j = 0; j < cols; j++){
            rowSum += matrix[i][j];
        }
    maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
}

// int diagonalSum(int matrix[][3], int n){
//     int sum=0;
//     for (int i = 0; i < n; i++){    //0(n*n)
//         for (int j = 0; j < n; j++){
//             if(i==j){
//                 sum+=matrix[i][j];
//             }else if (j==n-i-1){
//                 sum+=matrix[i][j];
//             }   
//         }
//     }
//     return sum;
// }
//OR
int diagonalSum(int matrix[][3], int n){
    int sum=0;
    for (int i = 0; i < n; i++){    //0(n*n)
        sum+=matrix[i][i];
        if (i!=n-i-1){
            sum+=matrix[i][n-i-1];
        }
    }
    return sum;
}


int main(){
    /*2D Array: int matrix [2][3];*/

    // int matrix [2][3]={{2,3,4},{4,5,5}};
    // cout<<matrix[1][0]<<endl;

    //can change values.

    //2. Loops on 2D Arrays: access by using  nested loops
    // int r,c;
    // cout<<"enter rows"<<endl;
    // cin>>r;
    // cout<<"enter columns"<<endl;
    // cin>>c;
    // int matrix [r][c];
    // int matrix[2][3]={{2,3,4},{8,5,5}};
    // int r=2,c=3;

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         // cout<<matrix[i][j]<<" ";
    //         cin>>matrix[i][j];
    //     }
    //     cout<<endl;
    // }
    //  cout<<"Your Output"<<endl;
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //         // cin>>matrix[i][j];
    //     }
    //     cout<<endl;
    // }

    // cout<<linearSearch(matrix, r, c, 8);

    //3. Row Major & Col Major 
    //4. In 2D Array index(i++) is replaced by cell(i,j)

    //5. Maximum row sum:
    int matrix[2][2]={{2,3},{8,5}};

    int Sum1=getMaxSum(matrix, 2,2);
    cout<<Sum1;

    //6. Max Col Sum h/w, linearsearch (i,j)pairs

    //7. Diagonal(r==c) Sum: PD , SD
    // int matrix[3][3]={{2,3,6},{8,4,5},{7,2,5}};
    // int n=3;
    // int diagSumResult=diagonalSum(matrix, n);
    // cout<<diagSumResult<<endl;


    return 0;
}