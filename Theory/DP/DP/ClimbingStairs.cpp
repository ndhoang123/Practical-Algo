// https://leetcode.com/problems/climbing-stairs/
// 06-Feb-2022

#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    if(n == 1) return 1;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int result = climbStairs(n);
    cout << result;
    return 0;
}