// https://leetcode.com/problems/find-the-difference/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t)
{
    unordered_map<char, int> hs;
    for(int i = 0; i < s.size(); i++)
    {
        hs[s[i]]++;
    }
    for(int i = 0; i < t.size(); i++)
    {
        if(--hs[t[i]] < 0) return t[i];
    }
    return '\0';
}

int main()
{
    string s = "";
    string t = "y";
    char rs = findTheDifference(s, t);
    cout << rs;
    return 0;
}