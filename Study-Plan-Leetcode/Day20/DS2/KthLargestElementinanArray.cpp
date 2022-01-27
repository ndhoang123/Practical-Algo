// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> h(nums.begin(), nums.end());
    for(int i = 1; i < k; i++){
        h.pop();
    }
    return h.top();
}

int main(){
    vector<int> nums{3,2,1,5,6,4};
    int k, result;
    cin >> k;
    result = findKthLargest(nums, k);
    cout << result;
    return 0;
}