// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n+1);
    for(int i = 2; i <= n; i++){
        int lastTwoStep = dp[i-2] + cost[i-2];
        int lastOneStep = dp[i-1] + cost[i-1];
        dp[i] = min(lastTwoStep, lastOneStep);
    }
    return dp[n];
}

int main(){
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    int result = minCostClimbingStairs(cost);
    cout << result;
    return 0;
}