// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> h;
    vector<int> ans;
    for(auto it : nums){
        h[it]++;
    }
    priority_queue<pair<int, int>> he;
    for(auto it : h){
        he.push(make_pair(it.second, it.first));
    }
    for(int i = 0; i < k; i++){
        ans.push_back(he.top().second);
        he.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums{1,1,1,2,2,3};
    vector<int> result = topKFrequent(nums, 2);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}