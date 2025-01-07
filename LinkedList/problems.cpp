#include<iostream>
#include<list>
using namespace std;

    Node* copyRandom(Node* head){
        if(head==NULL){
            return NULL:
        }

        unordered_mao<Node*, Node*> m;
        Node* newhead=new Node(head->val);
        Node* oldtemp=head->next;
        Node* newtemp=newhead;
        m[head]=newhead;
        while(oldtemp!=NULL){
            Node* copyNode=new Node(oldtemp->val);
            m(oldtemp)=copyNode;
            newtemp->next=copyNode;

            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        oldtemp=head;
        newtemp=head;
        while(oldtemp!=NULL){
            newtemp->random=m[oldtemp->random];
            
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;



    }



int main(){

    //LC_138:copy List with random pointers

    //step 1:make just simple copy(ignore random pointers)
    //step 2:recreate random connections to new linkedlist


    




    return 0;
}