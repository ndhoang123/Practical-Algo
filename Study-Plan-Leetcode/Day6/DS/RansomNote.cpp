// https://leetcode.com/problems/ransom-note/
#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> h;
    for(int i = 0; i < magazine.size(); i++){
        h[magazine[i]]++;
    }
    for(int i = 0; i < ransomNote.size(); i++){
        if(--h[ransomNote[i]] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    string ransomNote = "a", magazine = "aab";
    canConstruct(ransomNote, magazine) ? cout << "true" : cout << "false";
    return 0;
}