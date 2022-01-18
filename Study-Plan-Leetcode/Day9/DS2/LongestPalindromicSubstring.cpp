// https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    if(s.size() == 0) return s;
    int n = s.size();
    // bool v[n][n] = {false};
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        v[i][i] = true;
        if(i == n-1) break;
        v[i][i+1] = (s[i] == s[i+1]);
    }

    for(int i = n-3; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            v[i][j] = (v[i+1][j-1] && s[i] == s[j]);
        }
    }

    int max = 0;
    string maxStr = "";
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(v[i][j] == true && j-i+1 > max){
                max = j-i+1;
                maxStr = s.substr(i, j-i+1);
            }
        }
    }
    return maxStr;
}

int main(){
    string s;
    cin >> s;
    string str = longestPalindrome(s);
    cout << str;
    return 0;
}