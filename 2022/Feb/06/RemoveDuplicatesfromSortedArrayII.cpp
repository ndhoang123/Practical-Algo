// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for(int n : nums){
        if(i < 2 || n > nums[i-2]){
            nums[i++] = n;
        }
    }
    return i;
}

int main(){
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int result = removeDuplicates(nums);
    cout << result;
    return 0;
}