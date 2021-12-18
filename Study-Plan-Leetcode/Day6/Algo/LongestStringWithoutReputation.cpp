//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    // My method
    /*int max = 0, count = 0;
    unordered_map<char, int> hash;
    for (int j = 0; j < s.size(); j++)
    {
        hash.clear();
        count = 0;
        for (int i = j; i < s.size(); i++)
        {
            if (hash.find(s[i]) != hash.end())
            {
                if (count > max)
                    max = count;
                count = 1;
                hash.clear();
                hash[s[i]] = i;
            }
            else
            {
                count++;
                hash[s[i]] = i;
            }
        }
        if (max == 0 || count > max)
            max = count;
    }
    return max;
    */

    // Optimal method
    int i = 0, j = 0, ans = 0, n = s.size();
    unordered_set<char> set;
    while (i < n && j < n)
    {
        if (set.find(s[j]) == set.end())
        {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        }
        else
        {
            set.erase(s[i++]);
        }
    }
    return ans;
}

int main()
{
    string s = "abcabcabcbb";
    int value = lengthOfLongestSubstring(s);
    cout << value;
    return 0;
}