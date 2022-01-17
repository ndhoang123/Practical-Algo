// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> h;
    vector<vector<string>> result;
    for(auto it : strs){
        string temp = it;
        sort(temp.begin(), temp.end());
        h[temp].push_back(it);
    }

    for(auto it : h){
        result.push_back(it.second);
    }

    return result;
}

int main(){
    vector<string> stra {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(stra);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}