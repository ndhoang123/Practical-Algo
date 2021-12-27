#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int> &nums, int target){
    int first = 0;
    int last = nums.size() - 1;
    while(first <= last){
        int temp = (first + last) / 2;
        if(nums[temp] == target){
            return temp;
        }
        if(nums[temp] > target){
            last = temp - 1;
        }
        if(nums[temp] < target){
            first = temp + 1;
        }
    }
    return first;
}

int main() {
    vector<int> nums {1,3,5,6};
    int target = 2, result = 0;
    result = searchInsert(nums, target);
    cout << result;
    return 0;
}