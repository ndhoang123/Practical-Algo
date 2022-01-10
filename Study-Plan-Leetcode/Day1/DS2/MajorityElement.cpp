// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int counter = 0, majority;
    for(auto num : nums){
        if(counter == 0){
            majority = num;
        }
        counter += (num == majority) ? 1 : -1;
    }
    return majority;
}

int main(){
    vector<int> nums{1,1,1,3,3,3,2,3};
    int result = majorityElement(nums);
    cout << result;
    return 0;
}