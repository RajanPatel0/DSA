#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWord(string s){
    int n=s.length();
    string ans="";
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        string word="";
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if(word.length()>0){
            ans+=" "+word;
        }
    }
    return ans.substr(1);
}

int main(){

    //LC_151. Reverse Words in string: like hello world  =  world hello
    //1. complete reverse
    //2. then individual reverse(till i = space) by reverse(word.begin(), word.end())

    string result4=reverseWord("the pen");
    cout<<result4;

    return 0;
}