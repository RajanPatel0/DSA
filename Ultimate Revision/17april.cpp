#include<iostream>
#include <functional>
#include <bitset>
using namespace std;

// //LC_2667:function returning another function irrespective from it's input 
// var createHelloWorld = function() {
//     return function(...args) {  //no affect on any arguent
//         return "Hello World";
//     }
// };   OR
function<string()> createHelloWorld() {
    return []() {    //[]() is a lambda function in C++ that works like a returned function 
        return "Hello World";
    };
}
//---------------------------------

//LC_2620:Returning Counter with +1 on each call
// var createCounter = function(n) {
//     return function() {
//         return n++; 
//     };
// };   OR

function<int()> createCounter(int n) {
    return [n]() mutable {  //mutable lets the lambda modify the captured n
        return n++;    // return n, then increase it
    };
}
//---------------------------------------

//LC_109:Compliment of Base 10 integer
// 1.convert m to binary
// 2.flipping bits
// 3.convert flipped binary string back to decimals

int bitwiseComplement(int n) {
    if (n == 0) return 1;  // Special case

    int mask = 0;
    int temp = n;

    // Step 1: Build a mask of all 1's in the same bit-length as n
    while (temp > 0) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    // Step 2: XOR with mask flips only relevant bits
    return (~n) & mask;
}


int bitwiseComplement(int n) {
    if (n == 0) return 1;

    int mask = 0, temp = n;
    while (temp > 0) {
        mask = (mask << 1) | 1;  // Make a mask with all 1s
        temp >>= 1;
    }

    return (~n) & mask;
}



int main(){
    auto f = createHelloWorld();
    cout << f() << endl; // Hello World

    auto counter = createCounter(10);
    cout << counter() << endl; // 10
    cout << counter() << endl; // 11
    cout << counter() << endl; // 12


    return 0;
}