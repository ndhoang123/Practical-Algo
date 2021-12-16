// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Use for to add to hash with nums1, each of value in hash with nums1 will increase;
// Use for to find with nums2 the value corresponding to nums1. Each of value in hash will decrease if they match.
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> hash;
    vector<int> result;
    for(int i = 0; i < nums1.size(); i++) hash[nums1[i]]++;
    for(int i = 0; i < nums2.size(); i++){
        if(--hash[nums2[i]] >= 0) result.push_back(nums2[i]);
    }
    return result;
}

int main(){
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    vector<int> result = intersect(nums1, nums2);
    for(auto it: result){
        cout << it << " ";
    }
    return 0;
}