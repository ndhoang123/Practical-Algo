// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s){
    stack<char> q;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            q.push(s[i]);
        }
        else{
            if(q.empty()) return false;
            if((s[i] == ')' && q.top() != '(') || (s[i] == '}' && q.top() != '{') || (s[i] == ']' && q.top() != '[')){
                return false;
            }
            q.pop();
        }
    }
    return q.empty();
}

int main(){
    string s;
    cin >> s;
    isValid(s) ? cout << "True" : cout << "False";
    return 0;
}