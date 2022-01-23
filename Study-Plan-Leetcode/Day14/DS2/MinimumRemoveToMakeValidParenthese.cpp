// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s)
{
    string result = "";
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        if(s[i] == ')'){
            if(st.empty()){
                s[i] = '#';
            }
            else{
                st.pop();
            }
        }
    }
    while (!st.empty()){
        s[st.top()] = '#';
        st.pop();
    }

    for(int i = 0; i < s.size(); i++){
        if(s[i] != '#'){
            result.push_back(s[i]);
        }
    }
    return result;
}

int main(){
    string s = "))((";
    string result = minRemoveToMakeValid(s);
    cout << result << " ";
    return 0;
}