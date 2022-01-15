// https://leetcode.com/problems/longest-palindrome/

#include <bits/stdc++.h>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<int, int> h;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(h.find(s[i]) != h.end()){
            h.erase(s[i]);
            count++;
        }
        else{
            h[s[i]] = 1;
        }
    }
    if(!h.empty()) return count*2+1;
    return count*2;
}

int main(){
    string s;
    cin >> s;
    int result = longestPalindrome(s);
    cout << result;
    return 0;
}