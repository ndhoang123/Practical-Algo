// https://leetcode.com/problems/range-sum-query-immutable/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> ns;
public:
    NumArray(vector<int>& nums) {
        ns = nums;
    }
    
    int sumRange(int left, int right) {
        int count = 0;
        while(left <= right)
        {
            if(left == right) count += ns[left];
            else count += ns[left] + ns[right];
            left++;
            right--;
        }
        return count;
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