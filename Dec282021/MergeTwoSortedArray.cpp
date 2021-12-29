// https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    for(int i = 0; i < n; i++){
        nums1.push_back(0);
    }
    while(i >= 0 && j >= 0){
        if(nums1[i] < nums2[j]){
            nums1[k--] = nums2[j--];
        }
        else{
            nums1[k--] = nums1[i--];
        }
    }
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}

int main(){
    vector<int> nums1{1, 3, 5}, nums2{2, 4, 6};
    merge(nums1, 3, nums2, 3);
    for(auto it : nums1){
        cout << it << " ";
    }
    return 0;
}