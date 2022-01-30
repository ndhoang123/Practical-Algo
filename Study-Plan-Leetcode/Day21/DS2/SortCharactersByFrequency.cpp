// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>

using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> h;
    string result = "";
    priority_queue<pair<int, char>> he;
    for(auto it : s){
        h[it]++;
    }
    for(auto it : h){
        he.push(make_pair(it.second, it.first));
    }
    while(!he.empty()){
        int it = he.top().first;
        char st = he.top().second;
        he.pop();
        for(int i = 0; i < it; i++){
            result.push_back(st);
        }
    }
    return result;
}

int main(){
    string s = "cccaaa";
    string result = frequencySort(s);
    cout << result;
    return 0;
}