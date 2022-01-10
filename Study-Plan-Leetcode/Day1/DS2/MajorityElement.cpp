// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> h;
    for(auto num : nums){
        if(++h[num] > nums.size() / 2){
            return num;
        }
    }
    return 0;
}

int main(){
    vector<int> nums{3,2,3};
    int result = majorityElement(nums);
    cout << result;
    return 0;
}