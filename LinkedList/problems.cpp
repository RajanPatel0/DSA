#include<iostream>
#include<list>
#include<map>
#include<set>
#include <unordered_map>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};
// class prob{
//     Node* copyRandom(Node* head){
//         if(head==NULL){
//             return NULL;
//         }
//         unordered_map<Node*, Node*> m;s
//         Node* newhead=new Node(head->val);
//         Node* oldtemp=head->next;
//         Node* newtemp=newhead;
//         m(head)=newhead;
//         while(oldtemp!=NULL){
//             Node* copyNode=new Node(oldtemp->val);
//             m(oldtemp)=copyNode;
//             newtemp->next=copyNode;
//             oldtemp=oldtemp->next;
//             newtemp=newtemp->next;
//         }
//         oldtemp=head;
//         newtemp=head;
//         while(oldtemp!=NULL){
//             newtemp->random=m[oldtemp->random];
//             oldtemp=oldtemp->next;
//             newtemp=newtemp->next;
//         }
//         return newhead;
//     }
// };

class  solution{
    private:
    void insertTail(Node* head, Node* tail, int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    public:
    Node* copyList(Node* head){
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }

        //step2:create map
        unordered_map<Node*, Node*> oldtNew;
        Node* orgNode=head;
        Node* cloneNode=cloneHead;
        while(orgNode!=NULL){
            oldtNew[orgNode]=cloneNode;
            orgNode=orgNode->next;
            cloneNode=cloneNode->next;
        }
        while(!orgNode){
            cloneNode->random=oldtNew[orgNode->random];
            orgNode=orgNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};

int main(){

    //LC_138:copy List with random pointers

    //step 1:make just simple copy(ignore random pointers)
    //step 2:recreate random connections to new linkedlist


    return 0;
}