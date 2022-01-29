// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> h;
    int count = 0;
    vector<vector<int>> temp;
    vector<int> ans;
    for (auto it : nums)
    {
        h[it]++;
    }
    for (auto it : h)
    {
        temp.push_back(vector<int>(2));
        temp[count][0] = it.first;
        temp[count][1] = it.second;
        count++;
    }
    sort(temp.begin(), temp.end(), comp);
    for (int i = 0; i < k; i++)
    {
        ans.push_back(temp[i][0]);
    }
    return ans;
}

int main()
{
    vector<int> nums{-1, -1};
    vector<int> result = topKFrequent(nums, 1);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}