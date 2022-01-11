// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums)
{
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main(){
    vector<int> nums{2,0,2,1,1,0};
    sortColors(nums);
    for(auto it : nums){
        cout << it << " ";
    }
    return 0;
}