#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class circularList{
    Node*head;
    Node*tail;

    public:
    circularList(){ //constructor
        head=tail=NULL;
    }
    //insert at beiginning
    void insert_beg(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
            return;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;//(newNode)
        }
    }

    void insert_end(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
            return;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void delete_beg(){
        if(head==NULL){
            //
        }
    }

    void print(){
        if(head==NULL){
            return; 
        }
        else{
            cout<<head->data<<"->";
            Node* temp=head->next;
            while(temp!=head){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        cout<<head->data<<endl;
    }

};


int main(){
     circularList ll;
        ll.insert_beg(1);
        ll.insert_beg(2);
        ll.insert_beg(3);
        ll.insert_end(4);

        ll.print();

    return 0;
}