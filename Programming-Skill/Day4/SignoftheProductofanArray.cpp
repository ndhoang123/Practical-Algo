// https://leetcode.com/problems/sign-of-the-product-of-an-array/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int arraySign(vector<int> &nums)
{
    bool isPositive = true;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            return 0;
        if (nums[i] < 0)
            isPositive = !isPositive;
    }
    if (isPositive)
        return 1;
    return -1;
}

int main()
{
    vector<int> nums = {9,72,34,29,-49,-22,-77,-17,-66,-75,-44,-30,-24};
    int scr = arraySign(nums);
    cout << scr;
    return 0;
}