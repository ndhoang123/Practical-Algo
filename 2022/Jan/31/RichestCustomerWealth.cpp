// https://leetcode.com/problems/richest-customer-wealth/

#include <bits/stdc++.h>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int maxTillNow = 0;
    for(auto it : accounts){
        maxTillNow = max(maxTillNow, accumulate(it.begin(), it.end(), 0));
    }
    return maxTillNow;
}

int main(){
    vector<vector<int>> accounts{{1,5}, {7,3}, {3,5}};
    int result = maximumWealth(accounts);
    cout << result;
    return 0;
}