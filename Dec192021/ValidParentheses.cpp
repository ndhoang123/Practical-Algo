// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for(auto it : s){
        if(it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else{
            if(st.empty()) return false;
            if(it == ')' && st.top() != '(') return false;
            if(it == ']' && st.top() != '[') return false;
            if(it == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "(())";
    if(isValid(s)){
        cout << "True";
    }
    else{
        cout << "false";
    }
    return 0;
}