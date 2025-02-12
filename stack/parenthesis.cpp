#include<iostream>
#include<stack>
#include<vector>
#include<string>


using namespace std;

bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){ //opening
                st.push(s[i]);
            }else{  //closing
                if(st.size()==0){   //open<clo && this checking always before match finding
                    return false;
                }

                if((st.top()=='(' && s[i]==')')||   //matching
                (st.top()=='{' && s[i]=='}')||
                (st.top()=='[' && s[i]==']')){
                    st.pop();
                }else{  //no matching
                    return false;
                }
            }
        }

        return st.size()==0; //open > closing -(should be no opening char left)
    }

int main(){
    //LC_20:Valid Parenthesis ( { [ ] } )
    //1.last opening = first closing bracket -- (LIFO came in use)

    string s = "(]";
    cout<<isValid(s);

    return 0;
}