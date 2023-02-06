// https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int temp = 0;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] != 0){
                break;
            }
            if(nums[i] != nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
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