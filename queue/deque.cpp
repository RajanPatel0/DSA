#include<iostream>
#include<deque>
using namespace std;

//pop_front:front se pop as done before & front++

//pop_back:back se pop & rear got rear--


int main(){
    deque<int>dq;

    dq.push_back(10);   //insertion is from back rear & rear got rear++
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(50);
    dq.pop_back();
    dq.push_back(60);
    dq.push_back(70);
    dq.push_front(40);  //insertion is from *front and front got front--
    dq.pop_front();
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
        // dq.pop_back();
    }
    cout<<endl;



    return 0;
}