#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int index = nums.size() - (k % nums.size());
    for(int i = 0; i < index; i++){
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}

int main()
{
    vector<int> nums{-1, -100, 3, 99};
    rotate(nums, 2);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    return 0;
}