// https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int zeroCount = 0, l = 0;
    int window = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0) zeroCount++;
        while (zeroCount > k)
        {
            if(nums[l] == 0) zeroCount--;
            l++;
        }
        window = max(window, i - l + 1);
    }
    return window;
}

int main(){
    vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int result = longestOnes(nums, 3);
    cout << result;
    return 0;
}