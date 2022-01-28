// https://leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>

using namespace std;

vector<int> partitionLabels(string s)
{
    int n = s.size();
    vector<int> ans;
    vector<int> last_position(26, -1);
    unordered_map<char, int> h;
    for(int i = n-1; i >= 0; i--){
        if(last_position[s[i] - 'a'] == -1){
            last_position[s[i] - 'a'] = i;
        }
    }

    int minp = -1, len = 0;
    for (int i = 0; i < n; i++)
    {
        minp = max(minp, last_position[s[i] - 'a']);
        len++;
        if(minp == i){
            ans.push_back(len);
            minp = -1;
            len = 0;
        }
    }
    return ans;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}