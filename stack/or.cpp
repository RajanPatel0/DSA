#include<iostream>
#include<stack>
#include<vector>
#include<list>


using namespace std;

int main(){
    stack<int> s;   //by stack std implementation at starting header file

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}