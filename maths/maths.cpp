#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

string isprime(int n){  //1.Prime Number = BruteForce
    for (int i = 2; i*i <=n; i++){
        if (n%i==0){
            return "Non Prime";
        }
    }
    return "Prime";
}
//Or
int countprimes(int n){ //Sieve of Eratosthenes
    vector<bool> isPrime(n+1, true);
    int count=0;
    for (int i = 2; i < n; i++){   
        if(isPrime[i]){
            count++;
        for (int j = i*2; j < n; j=j+i){    //for not prime
                isPrime[j] = false;
            }
        }
    }
    return count;
}

void printDigits(int n){    //TC=0(log10 n) cuzz repeat perform by 10
    int count=0;
    while(n!=0){
        int digit=n%10;
        count++;// cout<<digit<<" ";   //can also perform count =count++ & sum+=digit
        n=n/10;
    }
    cout<<count;
}

bool isArmstrong(int n){
    int copyN=n;
    int sumOfCubes=0;

    while(n!=0){
        int dig=n%10;
        sumOfCubes+=(dig*dig*dig);
        n=n/10;
    }
    return sumOfCubes ==copyN;
}

int gcd(int a, int b){  //Euclid's Algorithm
    while(a>0 && b>0){
        if (a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0) return b;
    return a;
}

int lcm(int a, int b){
    int gcdVal=gcd(a,b);
    return (a*b)/gcdVal;
}

int reverseNum(int a){
    int revNum=0;
    while(a!=0){
        int digi=a%10;
        if(revNum>INT64_MAX || revNum<INT64_MIN/10){
            return 0;
        }
        revNum=(revNum*10)+digi;
        a=a/10;
    }
    return revNum;
}

bool palindrome(int n){
    // while(n!=0 && n>0){
        // if (reverseNum(n)==n)
        // {
        //     return 1;
        // }else{
        //     return 0;
        // }    //or
    // }
     if (n<0) return 0;
    return reverseNum(n)==n;
}



int main(){
    int n=45;   //1. Normal
    cout<<isprime(n)<<endl;

    //Sieve of Eratosthenes:1.) let all num as prime 
    //2.) go on each number & discard multiple of that no. from range
    //LC_204. Count Primes
    int primeResult=countprimes(50);
    cout<<primeResult<<endl;

    //3. Digits In a Number:
    printDigits(2878);
    cout<<endl;
    //OR Count can be found by
    // int n=2878;
    cout<<(int)(log10(2878)+1)<<endl;

    //4. Armstrong Number: number equals to the sum of cubes of its digits
    int m=153;
    if(isArmstrong(m)){
        cout<<"Yes It's a Armstrongn Number"<<endl;
    }else{
        cout<<"Not desired one"<<endl;
    }

    //5. GCD/HCF: highest common factor...by Euclid's Algorithm
    //if a>b : gcd(a%b,b) and vice versa for b>a : gcd(a,b%a)
    //repeated subtraction = division
    int gcdresult = gcd(20 , 28);
    cout<<gcdresult<<endl;

    //6. LCM: a*b/gcd(a,b)
    int lcmresult=lcm(20,28);
    cout<<lcmresult<<endl;

    //7. LC_7. Reversing a Number:
    int revNumResult= reverseNum(4537);
    cout<<revNumResult<<endl;

    //8. LC_9. Palindrome or Not:
    int palindromeresult=palindrome(355);
    if (palindromeresult){
        cout<<"yes palindrome";
    }else{
        cout<<"Not palindrome";
    }

    //9. Modulo Arithmatic: LC_850 Rectangle Area II--'ve to try
    // (x+y)%m=x%m+y%m
    // (x-y)%m=x%m-y%m
    // (x*y)%m=x%m*y%m
    // (x%y)%m..= same as first modulo

    return 0;
}