#include<iostream>
using namespace std;

//data, next, prev
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class doublyList{
    Node*head;
    Node*tail;

    public:
    doublyList(){
        head=tail=NULL;
    }
    //insert at beginning
    void push_front(int val){
        Node* newNode = new Node (val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    //insert at end
    void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    //delete from front
    void pop_front(){
        if (head==NULL){
            cout<<"List is Empty";
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }
    //delete at end
    void pop_back(){
        if(head==NULL){
            cout<<"LIst is Empty";
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
        // tail=temp;
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};


int main(){
    doublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.push_back(0);

    dll.pop_front();
    dll.pop_back();

    dll.print();

    return 0;
}