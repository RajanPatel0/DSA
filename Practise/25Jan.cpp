#include<iostream>
#include<algorithm>
#include<stack>
#include<cctype>
#include<string>
#include<stack>
using namespace std;

int linear(int arr[],int n, int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"found at index "<<i<<endl;
        }
    }
    return -1;
}

int binary(int arr[],int n, int target){
    int st=0;
    int end=n-1;
    int mid;
    while(st<=end){
        mid=st+(end-st)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){

    int arr[]={15,25,81,82,18};
    int n=5;

    // linear(arr,5,18);

    cout<<binary(arr,n,82);




    return 0;
}