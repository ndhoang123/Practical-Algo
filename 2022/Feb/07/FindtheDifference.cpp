// https://leetcode.com/problems/find-the-difference/

#include <bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t)
{
    char result = t[0];
    for(int i = 1; i < t.size(); i++){
        result ^= t[i];
    }
    for(int i = 0; i < s.size(); i++){
        result ^= s[i];
    }
    return result;
}

int main(){
    string s = "abcd", t = "abcde";
    char result = findTheDifference(s, t);
    cout << result;
    return 0;
}