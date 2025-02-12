#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

// class Stack{
//     vector<int> v;

//     public:
//     void push(int val){
//         v.push_back(val);
//     }

//     void pop(){
//         v.pop_back();
//     }

//     int top(){
//         return v[v.size()-1];
//     }

//     bool empty(){
//         return v.size()==0;
//     }

// };

class Stack{
    list<int> ll;

    public:
    void push(int val){
        ll.push_front(val);
    }

    void pop(){
       ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size()==0;
    }

};


int main(){
    //Stack using Vector(no-size limit)/Array(size limits)
    // Stack s;
    // s.push(20);
    // s.push(30);
    // s.push(40);

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;

    //Stack using Linked List: 1-2-3-4-5 (new node should be push front (as head))
    Stack l;
    l.push(20);
    l.push(30);
    l.push(40);

    while(!l.empty()){
        cout<<l.top()<<" ";
        l.pop();
    }
    cout<<endl;

    return 0;
}