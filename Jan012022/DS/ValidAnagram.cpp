// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t){
    unordered_map<char, int> h;
    for(int i = 0; i < t.size(); i++){
        h[s[i]]++;
        h[t[i]]--;
    }
    for(int i = 0; i < t.size(); i++){
        if(h[t[i]]){
            return false;
        }
    }
    return true;
}

int main(){
    string s, t;
    cin >> s >> t;
    isAnagram(s, t) ? cout << "true" : cout << "false";
    return 0;
}