// https://leetcode.com/problems/contains-duplicate/
#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    return set<int>(nums.begin(), nums.end()).size() < nums.size();
}

int main(){
    vector<int> nums{1,2,3,1};
    containsDuplicate(nums) ? cout << "True" : cout << "False";
    return 0;
}