// https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int lastNonZeroElement = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[lastNonZeroElement++] = nums[i];
        }
    }

    for(int i = lastNonZeroElement; i < nums.size(); i++){
        nums[i] = 0;
    }
}

int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }

    return 0;
}