// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_map<int, int> h;
    for(int i = 0; i < nums2.size(); i++){
        h[nums2[i]]++;
    }
    for(int i = 0; i < nums1.size(); i++){
        if(h.find(nums1[i]) != h.end() && h[nums1[i]] > 0){
            result.push_back(nums1[i]);
            h[nums1[i]]--;
        }
    }
    return result;
}

int main(){
    vector<int> nums1{4,9,5}, nums2{9,4,9,8,4};
    vector<int> result = intersect(nums1, nums2);
    for(auto it:result){
        cout << it << " ";
    }
    return 0;
}