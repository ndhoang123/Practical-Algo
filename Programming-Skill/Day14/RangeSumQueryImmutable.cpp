// https://leetcode.com/problems/range-sum-query-immutable/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            prefixSum.push_back(nums[i] + prefixSum[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left-1];
    }
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0,2);
    int param_2 = obj->sumRange(2,5);
    int param_3 = obj->sumRange(0,5);
    int param_4 = obj->sumRange(1,0);
    cout << "P1: " << param_1 << endl;
    cout << "P2: " << param_2 << endl;
    cout << "P3: " << param_3 << endl;
    cout << "P4: " << param_4 << endl;
    return 0;
}