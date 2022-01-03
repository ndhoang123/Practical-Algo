// https://leetcode.com/problems/single-number/
#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums){
    int result = 0;
    for(int i = 0; i < nums.size(); i++){
        result ^= nums[i];
    }

    return result;
}

int main(){
    vector<int> nums{2,2,1};
    cout << singleNumber(nums);
    return 0;
}