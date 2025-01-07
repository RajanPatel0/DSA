#include<iostream>
#include<string>
using namespace std;

//1.
bool isAlphanum(char ch){
    if((ch>='0' && ch<='9')||(
        tolower(ch)>='a' && tolower(ch)<='z'
    )){
        return true;
    }
    return false;
}
bool isPalindrome(string s){
    int st=0;
    int e=s.length()-1;
    while(st<e){
        if(!isAlphanum(s[st])){
            st++;
            continue;
        }
        if(!isAlphanum(s[e])){
            e--;
            continue;
        }
        if(tolower(s[st]) != tolower(s[e])){
            return false;
        }
        st++;
        e--;
    }
    return true;
}
//2.
string remOccur(string s, string part){
    while(s.length()>0 &&s.find(part)<s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    //LC_125. valid Palindrome:
    bool result1=isPalindrome("Ac3?e3c&a");
    cout<< result1<<endl;

    //LC_1910. Remove all Occurrences:
    //1. str.find(substr part)   --if valid ans then (it's < str.length())
    //2. str.erase(1,4)    --means to remove 4 size char from index 1
    string result2=remOccur("daabcbaabcbc", "abc");
    cout<<result2<<endl;
    
    return 0;
}