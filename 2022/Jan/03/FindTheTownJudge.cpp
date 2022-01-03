// https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> trusts(n + 1), trusted(n+1);
    for(auto it : trust){
        trusts[it[0]]++;
        trusted[it[1]]++;
    }
    for(int i = 1; i <= n; i++){
        if(trusts[i] == 0 && trusted[i] == n -1){
            return i;
        }
    }
    return -1;
}

int main(){
    int n = 3;
    vector<vector<int>> trust{{1, 2}, {2, 3}};
    int value = findJudge(n, trust);
    cout << value;
    return 0;
}