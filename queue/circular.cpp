#include<iostream>
#include<vector>
using namespace std;
//Circular Queue: Implementation using Array(fixed size)

class cirQueue{
    int* arr;   //for pointing to arr
    int currSize=0;
    int n;
    int f=0,r=-1;
    public:
    cirQueue(int size){
        n=size;
        arr=new int[n];
    }

    void push(int val){
        if(currSize==n){
            cout<<"CQ is Full";
            return;
        }
        r=(r+1)%n;
        arr[r]=val;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<<"CQ is Empty";
            return;
        }
        f=(f+1)%n;
        currSize--;
    }

    int front(){
        if(empty()){
            cout<<"CQ is Empty";
            return -1;
        }
        return arr[f];
    }
    bool empty(){
        return currSize==0;
    }

    void printArr(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


int main(){
    cirQueue cq(3);
    cq.push(2);
    cq.push(4);
    cq.push(6);
    cq.pop();
    cq.push(8);

    while(!cq.empty()){     //it'll print exact order from front(i.e from 4) to rear(8)
        cout<<cq.front()<<" ";
        cq.pop(); 
    }

    cout<<endl;
    cq.printArr();  //it'll print what it looks like



    return 0;
}