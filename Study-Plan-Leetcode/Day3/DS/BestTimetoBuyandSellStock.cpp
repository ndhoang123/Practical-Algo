// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int minTillNow = prices[0], maxTillNow = 0;
    for(int i = 0; i < prices.size(); i++){
        maxTillNow = max(maxTillNow, prices[i] - minTillNow);
        minTillNow = min(minTillNow, prices[i]);
    }
    if(maxTillNow < 0) return 0;
    return maxTillNow;
}

int main(){
    vector<int> prices{0, 6, -3, 7};
    int result = maxProfit(prices);
    cout << result;
    return 0;
}