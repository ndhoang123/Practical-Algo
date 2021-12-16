#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(nums[i] != 0){
                break;
            }
            if (nums[j] != nums[i])
            {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
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