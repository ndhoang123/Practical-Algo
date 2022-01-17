// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int count = 0;
    vector<vector<string>> result;
    if(strs.size() == 0) return result;
    unordered_map<string, int> h;
    for(int i = 0; i < strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if(h.find(temp) == h.end()){
            h[temp] = count;
            result.push_back(vector<string>());
            result[count].push_back(strs[i]);
            count++;
        }
        else{
            result[h[temp]].push_back(strs[i]);
        }
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