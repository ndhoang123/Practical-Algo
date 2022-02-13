// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;

void sets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs){
    subs.push_back(sub);
    for(int j = i; j < nums.size(); j++){
        sub.push_back(nums[j]);
        sets(nums, j+1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> sub;
    vector<vector<int>> subs;
    sets(nums, 0, sub, subs);
    return subs;
}

int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> result = subsets(nums);
    for(auto it : result){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}