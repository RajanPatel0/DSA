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

class List{
    Node* head;
    Node* tail;

    public:
    List(){     //just a default constructor to initialize
        head=tail=NULL;
    }
    //Operations:
    //1.insert at front(beg)=0(1)
    void push_front(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    //2.insert at end=0(1)
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    //3.delete at front(beg)=0(1)
    void pop_front(){
        if(head==NULL){
            cout<<"LL is Empty";
            return;
        }
        Node* temp;
        temp=head;  //delete karne wale head ko temp mei store kra diya 
        head=head->next;    //agle wale ko asli head bna diya
        temp->next=NULL;    //dereference temp(break connection)-seperating
        delete temp;    //then delete
    }
    //4.delete at end=0(n)
    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty";
            return;
        }else{
            Node* temp=head;
            while(temp->next!=tail){    //jab tak temp ka next tail ki value na de
                temp=temp->next;    //aage badhaoo
            }
            temp->next=NULL;   //phir temp ko original last banaoo
            delete tail;    //asli tail ko delete(connection break)
            tail=temp;
        }
    }
    //5.insert at any position=0(n)
    void insertAtPos(int val, int pos){
        if(pos<0){
            cout<<"Invalid position";
            return;
        }
        if(pos==0){
            push_front(val);
        }
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){ //agar koi invalid jyada pos pass kardi toh
                cout<<"Invalid";
                return;
            }
            temp=temp->next;
        }
        Node* newNode= new Node(val);   //newNode banaya jisme insert wali value hai
        newNode->next=temp->next;   //newNode ka next temp ke next ko point karega
        temp->next=newNode; //phir temp ke next ko newNode value dedo(point kra do)

    }
    //6.search in Linked list=0(n)
    int search(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    //7. traversing=0(n)
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List ll;

    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(5);
    ll.push_back(6);
    

    ll.pop_front();
    ll.pop_back();
    ll.insertAtPos(7,2);

    ll.print();
    cout<<ll.search(5)<<endl;
    cout<<ll.search(6)<<endl;
    






    return 0;
}