// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int letters[26] = {0};
    for (char c : p)
        letters[c - 'a']++;

    vector<int> result;
    int remaining = p.size(), j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j < s.size() && j - i < p.size())
        {
            if (letters[s.at(j++) - 'a']-- > 0)
                remaining--;
        }
        if (remaining == 0 && j - i == p.size())
            result.push_back(i);
        if (letters[s.at(i) - 'a']++ >= 0)
            remaining++;
    }
    return result;
}

int main()
{
    string s = "acdcaeccde";
    string p = "c";
    vector<int> result = findAnagrams(s, p);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}