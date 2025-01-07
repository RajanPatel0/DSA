#include<iostream>
#include<string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]){  //TC=O(1) cuzz of only 26 specific cases
    for (int i = 0; i <26; i++)
    {
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int freq[26]={0};   //cuzz we've limit i.e. only in lowercase

    for(int i=0; i<s1.length(); i++){
        int idx=s1[i]-'a';  //gives index like a->0  , b->1
        freq[idx]++;
    }

    int windSize=s1.length();
    for(int i =0; i<s2.length(); i++){
        int windidx=0, idx=i;
    int windFreq[26]={0};
        while(windidx < windSize && idx<s2.length()){
            windFreq[s2[idx]-'a']++;
            windidx++;
            idx++;
        }
        if(isFreqSame(freq, windFreq)){ //found
            return true;
        }
    }
    return false;
}

int main(){

    //LC_567:Permutation in String: checking exists or not 
    //1. storing frequency
    //2. window based searching 
    
    bool result3=checkInclusion("ab", "eidbooo");
    cout<<result3<<endl;

    return 0;
}