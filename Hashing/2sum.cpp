#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> sum(vector<int>& arr, int target){
    unordered_map<int,int>m;
    vector<int>ans;
    for(int i=0; i<arr.size();i++){
        int first=arr[i];
        int second=target-first;
        if(m.find(second)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first]=i;
    }
    return ans;
}
 
int main(){
    //LC_1: 2 Sum 
    vector<int> arr={5,2,11,7,15};
    int target=9;

    vector<int>sol=sum(arr,target);
    // Print the result
    if (!sol.empty()) {
        cout << "Indices of elements that sum to " << target << " are: ";
        for (int idx : sol) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "No two elements sum to " << target << "." << endl;
    }

    return 0;
}