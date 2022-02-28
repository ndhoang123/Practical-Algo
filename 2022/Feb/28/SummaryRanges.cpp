// https://leetcode.com/problems/summary-ranges/

#include <bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    const int n = nums.size();
    if(nums.size() == 0){
        return res;
    }
    for (int i = 0; i < n;)
    {
        int begin = i, end = i;
        while (end + 1 < n && nums[end+1] == nums[end] + 1)
        {
            end++;
        }
        if(begin == end){
            res.push_back(to_string(nums[begin]));
        }
        else{
            res.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
        }
        i = end+1;
    }
    return res;
    
}

int main()
{
    vector<int> nums{};
    vector<string> result = summaryRanges(nums);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}