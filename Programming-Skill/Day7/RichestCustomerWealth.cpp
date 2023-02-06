// https://leetcode.com/problems/richest-customer-wealth/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int acc = 0, maxVal = INT_MIN;
    for(int i = 0; i < accounts.size(); i++){
        acc = 0;
        for(int j = 0; j < accounts[i].size(); j++)
        {
            acc += accounts[i][j];
        }
        maxVal = max(maxVal, acc);
    }
    return maxVal;
}

int main()
{
    vector<vector<int>> acc = {{1,5},{7,3},{3,5}};
    int res;
    res = maximumWealth(acc);
    cout << res;
    return 0;
}