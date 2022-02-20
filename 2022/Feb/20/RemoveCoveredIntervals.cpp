// https://leetcode.com/problems/remove-covered-intervals/

#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int removeCoveredIntervals(vector<vector<int>> &intervals)
{
    unordered_set<int> h;
    int n = intervals.size() - 1, count = 0;
    sort(intervals.begin(), intervals.end(), compare);
    for (int i = n; i >= 0; i--)
    {
        if (h.find(i) == h.end())
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] && h.find(j) == h.end())
                {
                    count++;
                    h.insert(j);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (h.find(i) == h.end())
        {
            for (int j = i+1; j <= n; j++)
            {
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] && h.find(j) == h.end())
                {
                    count++;
                    h.insert(j);
                }
            }
        }
    }
    return n - count + 1;
}

int main()
{
    vector<vector<int>> intervals{{1, 4}, {3, 6}, {2, 8}};
    int result = removeCoveredIntervals(intervals);
    cout << result;
    return 0;
}