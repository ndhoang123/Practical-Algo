// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    vector<int> cur(26), goal(26);
    for(auto it:s1){
        cur[it - 'a']++;
    }
    for(int i = 0; i < s2.size(); i++){
        goal[s2[i] - 'a']++;
        if(i >= s1.size()) goal[s2[i-s1.size()] - 'a']--;
        if(goal == cur) return true;
    }

    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "ab";
    if (checkInclusion(s1, s2))
    {
        cout << "True";
    }
    else
    {
        cout << "false";
    }

    return 0;
}