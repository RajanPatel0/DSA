#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

//using Array
class Stack{
    #define N5
    int arr[5];
    int n=5;
    int top=-1;

public:
    void push(int val){
        if(top==n-1){
            cout<<"Stack Overflow";
        }else{
            top=top+1;
            arr[top]=val;
        }
    }

    void pop(){
        int item;
        if(top==-1){
            cout<<"Stack Underflow";
        }else{
            item=arr[top];
            top=top-1;
        }
    }

    int peek(){
        int item;
        if(top==-1){
            cout<<"Stack Underflow";
        }else{
            item = arr[top];
        }
    }

    bool empty(){
        return top==-1;
    }
    bool full(){
        return top==n-1;
    }
};


//using vector
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

//using Linked-List
// class Stack{
//     list<int> ll;

//     public:
//     void push(int val){
//         ll.push_front(val);
//     }

//     void pop(){
//        ll.pop_front();
//     }

//     int top(){
//         return ll.front();
//     }

//     bool empty(){
//         return ll.size()==0;
//     }

// };


int main(){
    //Stack using Array
    Stack arr;
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.pop();
    arr.push(40);
    arr.push(50);    
    while(!arr.empty()){
        cout<<arr.peek()<<" ";
        arr.pop();
    }
    cout<<endl;

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
    // Stack l;
    // l.push(20);
    // l.push(30);
    // l.push(40);

    // while(!l.empty()){
    //     cout<<l.top()<<" ";
    //     l.pop();
    // }
    // cout<<endl;

    return 0;
}