#include<iostream> 
#include<stack>
#include<vector>
using namespace std;
//STACK INTERVIEW QUESTIONS:

//1:reverse a string using stack
int reverse(string str){
    stack<int>s;

    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char ch=s.top();
        cout<<ch;
        s.pop();
    }
}

//2: delete middle element from stack
void solve (stack<int>& inputStack, int count, int n){
    //count for each traverse && n is for size N
    if(count==n/2){ //base case
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
}

void deleteMid(stack<int>& inputStack, int N){
    int count=0;
    solve(inputStack, count, N);

}

int main(){
    string str="rajan";
    reverse(str);




    return 0;
}