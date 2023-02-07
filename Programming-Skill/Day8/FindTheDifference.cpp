// https://leetcode.com/problems/find-the-difference/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t)
{
    char ch = t[0];
    for(int i = 1; i < t.size(); i++)
    {
        ch ^= t[i];
    }
    for(int i = 0; i < s.size(); i++)
    {
        ch ^= s[i];
    }
    return ch;
}

int main()
{
    string s = "";
    string t = "y";
    char rs = findTheDifference(s, t);
    cout << rs;
    return 0;
}