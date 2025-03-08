#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Implementing Min Stack to getMin function

class Stack{
    stack<long long int>s;
    long long int minVal;

    public:
    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal=val;
        }else{
            if(val<minVal){
                s.push(2*val-minVal);   //or s.push(int val2= 2*val-minVal)
                minVal=val;
            }else{
                s.push(val);
            }
        }
        cout<<val<<" pushed"<<endl;
    }

    void pop(){
        if(s.top()<minVal){ //minVal update by checking just before pop 
            minVal=2*minVal-s.top();    //or minVal=2*minVal-val2;
        }
        s.pop();
        cout<<"val popped"<<endl;
    }

    int top(){
        if(s.top()<minVal){ //agr top wali value formula adjusted wali hui toh original minVal update return hogi
            cout<<"Top is: "<<minVal<<endl;
        }
        cout<<"Top is: "<<s.top()<<endl;    //agr just normal value(non-formula adjusted) top pe hui toh just top return
    }

    int getMin(){
        cout<<"Min is: "<<minVal<<endl;
    }
};

int main(){
    Stack ex;

    ex.push(-2);
    ex.push(-0);
    ex.push(-3);
    ex.getMin();
    ex.pop();
    ex.top();
    ex.getMin();
    
    cout<<"That's All Thanks:)";

    return 0;
}