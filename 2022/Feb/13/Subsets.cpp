// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size(), p = 1 << n;
    vector<vector<int>> h(p);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < nums.size(); j++){
            if((i >> j) & 1){
                h[i].push_back(nums[j]);
            }
        }
    }
    return h;
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