#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){  //constructor
        data=val;   //assign val to data of which we want to create node
        next=NULL;
    }
};

class Queue{
    Node*head;
    Node*tail;

public:
    Queue(){    //constructor
        head=tail=NULL;
    }

    void push(int val){
        Node* newNode= new Node(val);
        if(isEmpty()){
            head=tail=newNode;
        }else{
             tail->next=newNode;
             tail=newNode;  //assigning new tail to newNode
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"LL is empty";
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    int front(){
        if(isEmpty()){
            cout<<"LL is empty";
            return -1;
        }
        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }   

};



int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;




    return 0;
}