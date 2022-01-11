// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(begin(intervals), end(intervals));
    vector<vector<int>> ans{intervals[0]};
    for(auto it : intervals){
        if(it[0] <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
        else{
            ans.push_back(it);
        }
    }
    return ans;
}

int main(){
    // vector<vector<int>> intervals{{1,3}, {8,10}, {2,6}, {15,18}};
    vector<vector<int>> intervals{{1,4}, {0,0}};
    vector<vector<int>> result = merge(intervals);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
    }
    return 0;
}