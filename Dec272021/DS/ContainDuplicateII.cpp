// https://leetcode.com/problems/contains-duplicate-ii/
#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> h;
    for(int i = 0; i < nums.size(); i++){
        if(h.find(nums[i]) != h.end() && abs(i - h[nums[i]]) <= k){
            return true;
        }
        h[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> nums{1,0,2,1};
    containsNearbyDuplicate(nums, 1) ? cout << "True" : cout << "False";
    return 0;
}