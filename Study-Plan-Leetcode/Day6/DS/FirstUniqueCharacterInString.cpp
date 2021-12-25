// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> h;
    for(auto it : s){
        h[it]++;
    }
    for(int i = 0; i < s.size(); i++){
        if(h[s[i]] == 1) return i;
    }
    return -1;
}

int main(){
    string s;
    cin >> s;
    int result = firstUniqChar(s);
    cout << result;
    return 0;
}