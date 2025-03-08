#include<iostream>
#include<algorithm>
using namespace std;

int bubble(int arr[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int selection(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1; i<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        } 
        swap(arr[minIdx],arr[i]);
    }
}



int main(){

    int arr[]={1,2,4,7,4,84,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Without Sorted: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    // bubble(arr,7);
    selection(arr,size);
    cout<<"Sorted: "<<endl;
    for(int j=0;j<size;j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}