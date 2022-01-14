// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
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