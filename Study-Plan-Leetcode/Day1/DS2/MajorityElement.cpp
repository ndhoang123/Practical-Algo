// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    if(nums.empty()) return 0;
    unordered_map<int, int> h;
    int max = 0, temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(h.find(nums[i]) != h.end()){
            h[nums[i]]++;
        }
        else{
            h[nums[i]] = 1;
        }
    }
    for(auto it : h){
        if(it.second > temp){
            temp = it.second;
            max = it.first;
        }
    }
    return max;
}

int main(){
    vector<int> nums{2,2,1,1,1,2,2};
    int result = majorityElement(nums);
    cout << result;
    return 0;
}