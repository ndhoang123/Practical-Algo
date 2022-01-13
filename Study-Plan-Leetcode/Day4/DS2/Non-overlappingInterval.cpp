// https://leetcode.com/problems/non-overlapping-intervals/

#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ans = -1;
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end(), comp);
    vector<int> prev = intervals[0];

    for(int i = 0; i < intervals.size(); i++){
        for(auto it : intervals[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    for(vector<int> i:intervals){
        if(prev[1] > i[0]){
            ans++;
        }
        else{
            prev = i;
        }
    }

    return ans;
}

int main(){
    // vector<vector<int>> intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    vector<vector<int>> intervals{{1,8}, {2,3}, {3,4}, {5, 9}};
    int result = eraseOverlapIntervals(intervals);
    cout << result;
    return 0;
}