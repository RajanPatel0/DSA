#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//Implementation using Array/Vector 
class Queue{
    #define N100
    int front;
    int rear;
    int n;
    int* arr;

public:
    Queue(){
        front=rear=0;
        n=100;
        arr=new int[n];
    }

    void push(int val){
        if(rear==n){
            cout<<"Queue is Full"<<endl;
            return;
        }else{
            arr[rear]=val;
            rear++;
        }
    }

    void pop(){
        if (isEmpty()){
            return;    
        }else{
            int ans=arr[front];
            ans=-1;
            front++;
            if(front==rear){    //if we've to pop at first index
                front=0;
                rear=0;
            }
            cout<< ans;
        }
    }

    int front(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return front==rear;
    }

};









int main(){

    // queue<int> q;

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // cout<<"size of queue is: "<<q.size()<<endl;
    // q.pop();
    // cout<<"size of queue is: "<<q.size()<<endl;

    Queue qu;

    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.isEmpty();
    qu.pop();
    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;



    return 0;
}