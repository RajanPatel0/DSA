#include<iostream>
#include<vector>
using namespace std;

int fib(int n){ //1
    if(n==0||n==1){
        return n; 
    }
    return fib(n-1)+fib(n-2);
}

bool isSorted(vector<int> arr, int n){  //2
    if(n==0||n==1){ //n-1 size arr should always in this base case
        return true;
    }
    return (arr[n-1]>=arr[n-2] && isSorted(arr,n-1));
}

int binSrch(vector<int>a, int target,int st,int end){
    if(st<=end){
    int mid=st+(end-st)/2;
    if(a[mid]==target)return mid;
    else if(a[mid]<=target){ 
        return binSrch(a,target,mid+1,end);
    }else{
        return binSrch(a,target,st,mid-1);
    }
    }
    return -1;
}

int main(){
    //nth Fibonacci term 509: 0,1,1,2,3,5,8,13,...
    //Tc:total calls*work done in each=0(2^n)

    int n=6;

    cout<<fib(n)<<endl; //8

    //check if array sorted or not
    //Tc:0(n) - Sc:0(n)
    vector<int> arr={1,8,2,4,5};
    int m=arr.size();
    cout<<isSorted(arr,m)<<endl;  //0

    //Recursive Binary Search 704:
    //Tc:0(log(n)) - Sc:0(log(n));
    vector<int> array={1,2,3,4,5,6,7,8};
    int k=arr.size();

    cout<<binSrch(array,5,0,k-1);



    return 0;
}