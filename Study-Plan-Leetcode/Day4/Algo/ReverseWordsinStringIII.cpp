// https://leetcode.com/problems/reverse-words-in-a-string-iii/
#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    int front = 0;
    for(int i = 0; i <= s.size(); ++i){
        if(i == s.size() || s[i] == ' '){
            reverse(&s[front], &s[i]);
            front = i + 1;
        }
    }
    return s;
}

int main()
{
    string str = "Let's take LeetCode contest";
    string result = reverseWords(str);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}