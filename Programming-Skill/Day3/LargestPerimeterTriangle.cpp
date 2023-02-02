// https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

bool isTriangle(int num1, int num2, int num3)
{
    if((num1 < num2 + num3 && num1 > abs(num2 - num3)) || (num2 < num1 + num3 && num2 > abs(num1 - num3))
    || (num3 < num2 + num1 && num3 > abs(num2 - num1))){
        return true;
    }
    return false;
}

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int p = 0, i = 0;
    while(i + 2 < nums.size())
    {
        if(isTriangle(nums[i], nums[i+1], nums[i+2]) && nums[i]+nums[i+1]+nums[i+2] > p){
            p = nums[i]+nums[i+1]+nums[i+2];
        }
        i++;
    }
    return p;
}

int main()
{
    vector<int> nums = {1,2,1,10};
    int res = largestPerimeter(nums);
    cout << res;
    return 0;
}