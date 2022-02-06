// https://leetcode.com/problems/climbing-stairs/
// 06-Feb-2022

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, int> h;
    int dp(int n){
        if(n <= 2) return n;
        if(h.find(n) == h.end()){
            h[n] = dp(n-1) + dp(n-2);
        }
        return h[n];
    }

public:
    int climbStairs(int n) {
        return dp(n);
    }
};

int main(){
    int n;
    cin >> n;
    Solution s = Solution();
    int result = s.climbStairs(n);
    cout << result;
    return 0;
}