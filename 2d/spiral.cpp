#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat){
    int m=mat.size(),n=mat[0].size();
    int strow=0,stcol=0;
    int endrow=m-1,endcol=n-1;
    vector<int> ans;
    while(strow<=endrow && stcol<=endcol){  //handles even & odd order matrix
        for (int j = stcol; j <= endcol; j++){   //  top
            ans.push_back(mat[strow][j]);
        }
        for (int i = strow+1; i <= endrow; i++){   //right
            ans.push_back(mat[i][endcol]);
        }
        for (int j = endcol-1; j <= stcol; j--){   //bottom
            if(strow==endrow){
            break;
            }
            ans.push_back(mat[endrow][j]);
        }
        for (int i = endrow-1; i <= strow+1; i--){   //left
            if(stcol==endcol){
                break;
            }
            ans.push_back(mat[i][stcol]);
        }
        strow++,endrow--,stcol++,endcol--;
    }
    return ans;
}


int main(){

    //LC 54: Done
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> result = spiralMatrix(matrix);
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }


    return 0;
}