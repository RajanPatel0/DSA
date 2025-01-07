#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int>> mat={{1,3,5},{2,4,6,1,7},{5,9,3}};
    
    //cout<<mat[1][1]<<endl;
    // int rows=mat.size();
    // int cols=mat[i].size();

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //here in 2d vector we can add extra element cuzz of dynamic sizing


    return 0;
}