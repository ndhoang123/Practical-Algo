// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <bits/stdc++.h>

using namespace std;

int longestSubarray(vector<int> &nums, int limit)
{
    multiset<int> m;
    int j = 0, ans = 1;
    for(int i = 0; i < nums.size(); i++){
        m.insert(nums[i]);
        while(!m.empty() && *m.rbegin() - *m.begin() > limit){
            m.erase(m.find(nums[j++]));
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}

int main()
{
    vector<int> nums{1,5,6,7,8,10,6,5,6};
    int result = longestSubarray(nums, 4);
    cout << result;
    return 0;
}