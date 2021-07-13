#include<bits/stdc++.h>

using namespace std;

bool isValidParen(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else {
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == ']' && st.top() != '[') return false;
            if(c == '}' && st.top() != '{') return false;
            st.pop();
        }
    }

    return st.empty();
}

int main(){
    string s = "(([]){})";
    if(isValidParen(s)){
        cout << "True";
    }

    else {
        cout << "False";
    }
    return 0;
}