// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> r;
    if(s.size() < 10) return r;
    unordered_map<string, int> h;
    for(int i = 0; i < s.size()-9; i++){
        h[s.substr(i, 10)]++;
    }
    for(auto it : h){
        if(it.second > 1){
            r.push_back(it.first);
        }
    }
    return r;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = findRepeatedDnaSequences(s);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}