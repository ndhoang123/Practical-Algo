// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    vector<int> v(nums.size());
    v[0] = nums[0];
    v[1] = max(v[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
        v[i] = max(v[i-1], v[i-2] + nums[i]);
    }
    return v[nums.size() - 1];
}

int main(){
    vector<int> nums{1,2,3,1};
    int result = rob(nums);
    cout << result;
    return 0;
}