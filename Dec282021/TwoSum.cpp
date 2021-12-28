// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> h;
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        if(h.find(target - nums[i]) != h.end()){
            result.push_back(h[target - nums[i]]);
            result.push_back(i);
        }
        else{
            h[nums[i]] = i;
        }
    }
    return result;
}

int main(){
    vector<int> nums{3,2,4};
    vector<int> result = twoSum(nums, 6);
    for(auto it: result){
        cout << it << " ";
    }

    return 0;
}