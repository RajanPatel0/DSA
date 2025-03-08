#include<iostream>
#include<queue> //here it is
using namespace std;

int main(){

    queue<int>q;    //queue of integer type

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;



    return 0;
}