// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>

using namespace std;

/*
    - k is size of s1, and cur, goal array to store value of each of keyword.
    - We use the window sliding method to find the result, with k.
    1. Firstly, we iterate all value in s1, and assign it into the cur array. With the index, each of value we count from the 'a' word.
    2. Secondly, we use loop to iterate all value in s2. 
    3. We add value in the goal array with the index, couting from the 'a' word. And escalating the value correspond to the index.
    4. Next, we use condition to check the index is more than the size of s1. If so, they will decrease the value of index in goal array, that index is s2[i - s1.size()] -> the index is gonna point to the position before the k size of current index, the index is in last of k size.
    5. After that, they will compare between the goal and cur. If satifies, they return true. Otherwise, they must continue.
*/

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