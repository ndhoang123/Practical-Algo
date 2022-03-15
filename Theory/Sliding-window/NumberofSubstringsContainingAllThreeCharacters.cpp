// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>

using namespace std;

int numberOfSubstrings(string s)
{
    int arr[3] = {-1, -1, -1}, res = 0, n = s.size();
    for(int i = 0; i < n; ++i)
    {
        arr[s[i] - 'a'] = i;
        res += 1 + min({arr[0], arr[1], arr[2]});
    }
    return res;
}

int main(){
    string s = "abcabc";
    int result = numberOfSubstrings(s);
    cout << result;
    return 0;
}