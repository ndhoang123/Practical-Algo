//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int max = 0, count = 0;
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
}

int main()
{
    string s = "dvdf";
    int value = lengthOfLongestSubstring(s);
    cout << value;
    return 0;
}