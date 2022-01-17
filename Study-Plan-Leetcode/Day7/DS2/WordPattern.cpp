// https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s){
    string str = "";
    vector<string> v;
    for(int i = 0; i < s.size()+1; i++){
        if(s[i] == ' ' || i == s.size()){
            v.push_back(str);
            str = "";
        }
        else{
            str += s[i];
        }
    }
    return v;
}

bool wordPattern(string pattern, string s) {
    vector<string> str = split(s);
    unordered_map<char, string> h;
    unordered_set<string> se;
    if(pattern.size() > str.size() || pattern.size() < str.size()) return false;
    for(int i = 0; i < pattern.size(); i++){
        if(h.find(pattern[i]) == h.end() && se.find(str[i]) == se.end()){
            h[pattern[i]] = str[i];
            se.insert(h[pattern[i]]);
        }
        else if(h.find(pattern[i]) != h.end() && h[pattern[i]] != str[i]){
            return false;
        }
        else if(h.find(pattern[i]) == h.end() && se.find(str[i]) != se.end()){
            return false;
        }
    }
    return true;
}

int main(){
    string pattern, s;
    pattern = "abba";
    s = "dog dog dog dog";
    wordPattern(pattern, s) ? cout << "True" : cout << "False";
    return 0;
}