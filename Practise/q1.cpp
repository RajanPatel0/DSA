#include<iostream> 
#include<algorithm>
#include<stack>
#include<cctype>
using namespace std;
// #define MAX 100

void atEnd(int arr[], int &n, int element){
    arr[n++]=element;
}

void atPos(int arr[], int &n,int pos, int element){
    for (int i = n++; i >pos; i--) arr[i]=arr[i-1];
        arr[pos]=element;
}

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void dbyVal(int arr[], int &n, int value){
    int pos=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==value)
        {
            pos=i;
            break;
        }
    }

    if (pos==-1)
    {
        cout<<"value is'nt in array"<<endl;
    }
    
    for (int i =pos; i <n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    cout << "Element " << value << " deleted.\n";
}

void dbyPosition(int arr[], int &n, int position){
    
    if (position <0 || position >=n)
    {
        cout<<"invalid Position";
    }
    
    
    for (int i =position; i <n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    cout << "Element at position " << position << " deleted.\n";
}

int linear(int arr[], int n, int target){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}

int binary(int arr[], int n, int target){
    int s=0, e=n-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if (arr[mid]==target)
        {
            return mid;
        }else if(arr[mid]<target){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;
}

// class Stack
// {
// private:
//     int arr[MAX];
//     int top;
// public:
//     Stack(){top=-1;}

//     void push(int val){
//         if(isFull()){
//             cout<<"stack is Full";
//             return;
//         }else{
//             arr[top++]=val;
//             cout<<"pushed "<<val;
//         }
//     }

//     void pop(){
//         if (isEmpty())
//         {
//             cout<<"stack is empty";
//             return;
//         }else{
//             cout<<"pushed "<<arr[top--];
//         }
//     }

//     void peek(){
//         if (isEmpty())
//         {
//             cout<<"stack is empty";
//             return;
//         }else{
//             cout<<"top is: "<<arr[top];
//         }
//     }

//     bool isEmpty(){
//         return ==-1;
//     }
    
//     bool isFull(){
//         return == MAX-1;
//     }
// };

int EvalPostfix(string expression){
    stack<int>s;
    for (char ch : expression)
    {
        if(isdigit(ch)){    //covert char to int
            s.push(ch-'0');
        }
        else{
            int b=s.top(); s.pop();
            int a=s.top(); s.pop();
            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }
    return s.top();
}

int main(){

    int arr[10]={10,20,30,40,50};
    int n=5;

    atEnd(arr,n ,60);
        display(arr, n);
    cout<<endl;

    atPos(arr, n, 2, 25);

    display(arr, n);

    // Delete by value
    int value = 40;
    dbyVal(arr, n, value);
    cout << "Array after deleting value " << value << ": ";
    display(arr, n);

    // Delete by position
    int position = 2;
    dbyPosition(arr, n, position);
    cout << "Array after deleting position " << position << ": ";
    display(arr, n);

    cout<<linear(arr, 5, 30)<<endl;

    cout<<binary(arr, 5, 50)<<endl;
    
    string postfix = "53+82-*";
    cout<<EvalPostfix(postfix);

    return 0;

}