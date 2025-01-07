#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

void printSs(vector<int> &arr, vector<int> &ans, int i){    //recursion tree(via inclusion & exclusion)
    if(i==arr.size()){  //Base Case
        for(int val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    //include:
    ans.push_back(arr[i]);
    printSs(arr,ans,i+1);
    
    ans.pop_back();
    //Exclude:
    printSs(arr, ans, i+1);
}



//90
void getsub(vector<int>& nums,vector<int>&ans,int i,vector<vector<int>>&allset){
        if(i==nums.size()){
            allset.push_back(ans);
            return;
        }

    ans.push_back(nums[i]);
    getsub(nums,ans,i+1,allset);
    
    ans.pop_back();
    int idx=i+1;    //stop excluding condtn
    while(idx<nums.size() && nums[idx]==nums[idx-1])idx++;
    //Exclude:
    getsub(nums, ans, idx,allset);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allset;
        vector<int> ans;

        getsub(nums,ans,0,allset);
        return allset;
    }






int main(){

    //Print All Subsets (using recursion):
    vector<int> arr={1,2,3};
    vector<int>ans;
    printSs(arr,ans,0);

    //LC_78(unique)
    //LC_90(duplicate)==exclude choice set up

    return 0;
}