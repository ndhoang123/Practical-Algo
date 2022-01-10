// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    if(nums.empty() || nums.size() < 3) return result;

    size_t n_size = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n_size; i++){
        if(nums[i] > 0) break;

        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i+1, right = n_size - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum > 0){
                right--;
            }
            else if (sum < 0){
                left++;
            }
            else{
                result.push_back({nums[i], nums[left], nums[right]});
                int last_left = nums[left], last_right = nums[right];
                while(left < right && last_left == nums[left]) ++left;
                while(left < right && last_right == nums[right]) --right;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
    }
    return 0;
}