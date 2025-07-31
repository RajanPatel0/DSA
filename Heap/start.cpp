#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size=0;

    void insert(int val){
        size=size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};



int main(){

    Heap h;
    h.insert(60);
    h.insert(65);
    h.insert(63);
    h.insert(62);
    h.insert(64);
    
    h.print();  //for printing output


    return 0;
}