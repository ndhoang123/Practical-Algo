// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for(auto it : nums){
        if(first > it){
            first = it;
        }
        else if(first < it && it < second){
            second = it;
        }
        else{
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> nums{5,4,3,2,1};
    increasingTriplet(nums) ? cout << "True" : cout << "False";
    return 0;
}