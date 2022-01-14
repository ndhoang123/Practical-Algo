// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(nums.size());
    vector<int> right(nums.size());
    vector<int> result(nums.size());
    left[0] = 1;
    right[n-1] = 1;
    for(int i = 1; i < n; i++){
        left[i] = left[i-1]*nums[i-1];
    }
    for(int j = n-2; j >= 0; j--){
        right[j] = right[j+1]*nums[j+1];
    }
    for(int i = 0; i < n; i++){
        result[i] = left[i]*right[i];
    }

    return result;
}

int main(){
    vector<int> nums{0,0,1,0,1};
    vector<int> result = productExceptSelf(nums);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}