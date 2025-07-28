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

    https://chat.whatsapp.com/HTk1HUyPlGQKpHgMDBpEFW

    https://chat.whatsapp.com/C73iEJw0nRhCH46UHpATtd
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};



int main(){

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    h.print();


    return 0;
}