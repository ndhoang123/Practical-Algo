// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>

using namespace std;
// Kadane's Algorithm
int maxSubArray(vector<int>& nums){
    int curMax = 0, maxTillNow = INT_MIN;
    for(auto it : nums){
        curMax = max(it, curMax + it);
        maxTillNow = max(maxTillNow, curMax);
    }
    return maxTillNow;
}

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(nums);
    cout << result;
    return 0;
}