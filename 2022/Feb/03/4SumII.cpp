// https://leetcode.com/problems/4sum-ii/

#include <bits/stdc++.h>

using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    map<int, int> h;
    int result(0);
    for(auto k : nums3){
        for(auto l : nums4){
            h[k+l]++;
        }
    }
    for(auto i : nums1){
        for(auto j : nums2){
            result += h[-(i+j)];
        }
    }
    return result;
}

int main()
{
    vector<int> nums1{1,2};
    vector<int> nums2{-2,-1};
    vector<int> nums3{-1,2};
    vector<int> nums4{0,2};
    int result = fourSumCount(nums1, nums2, nums3, nums4);
    cout << result;
    return 0;
}