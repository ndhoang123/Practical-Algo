// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>

using namespace std;
// Divine and conquer
int maxArray(vector<int>& nums, int L, int R){
    if(L > R) return INT_MIN;
    int mid = (L + R)/2, leftSum = 0, rightSum = 0;
    for(int i = mid-1, curSum = 0; i >= L; i--){
        curSum += nums[i];
        leftSum = max(curSum, leftSum);
    }
    for (int i = mid+1, curSum = 0; i <= R; i++)
    {
        curSum += nums[i];
        rightSum = max(curSum, rightSum);
    }
    return max({maxArray(nums, L, mid-1), maxArray(nums, mid+1, R), leftSum + nums[mid] + rightSum});
}

int maxSubArray(vector<int>& nums){
    return maxArray(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(nums);
    cout << result;
    return 0;
}