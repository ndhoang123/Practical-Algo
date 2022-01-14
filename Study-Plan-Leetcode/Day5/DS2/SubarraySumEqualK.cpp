// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    int sum = 0;
    unordered_map<int, int> h;
    h[0]++;
    for (int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
        if(h.find(sum-k) != h.end()){
            count += h[sum-k];
        }
        h[sum]++;
    }
    return count;
}

int main()
{
    vector<int> nums{100,1,2,3,4};
    int k;
    cin >> k;
    int result = subarraySum(nums, k);
    cout << result;
    return 0;
}