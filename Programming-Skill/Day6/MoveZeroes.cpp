// https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    vector<int> nums1(nums.size(), 0);
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0){
            nums1[j] = nums[i];
            j++;
        }
    }
    nums = nums1;
}

int main()
{
    vector<int> nums = {1, 0, 1, 2, 0, 3};
    moveZeroes(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}