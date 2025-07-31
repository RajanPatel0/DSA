#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int index = size;
        arr[index] = val;

        while(index>1){     //0(log(n))
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

    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing To Delete"<<endl;
            return;
        }

        arr[1]=arr[size]; //last ko root(starting pehle) mei daal diya
        size--; //removing last element jo ki swapped root hoga

        //Take curr root to its correct position
        int i=1;
        while(i<=size){
            int leftIdx=2*i;
            int rightIdx=2*i+1;

            if(leftIdx<size && arr[i]<arr[leftIdx]){
                swap(arr[i], arr[leftIdx]);
                i=leftIdx;
            }else if(rightIdx<size && arr[i]< arr[rightIdx]){
                swap(arr[i], arr[rightIdx]);
                i=rightIdx;
            }else{
                return;
            }
        }
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

    h.deleteFromHeap();

    h.print();

    return 0;
}