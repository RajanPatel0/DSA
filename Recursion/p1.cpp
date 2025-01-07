#include<iostream>
using namespace std;

// void abc(){
//     abc();
// }

//Tc: no.of rec calls * work on each call
//Sc: height of call stack * memory in each call

void printNum(int n){
    if(n==1){   //base case-for check
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    printNum(n-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int numSum(int n){
    if(n==1){
        return 1;
    }
    return n+numSum(n-1);
}

int main(){
    //Recursion:Fnx calls itself
    // main->abc->abc->abc->end(base-case)
    int n=4;
    printNum(n);
    cout<<endl;
    //N Factorial
        cout<< factorial(n)<<endl;;

    //Sum of N Numbers
    cout<<numSum(n);


    return 0;
}