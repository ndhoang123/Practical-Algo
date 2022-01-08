// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include <bits/stdc++.h>

using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    int count = 0;
    int map[60] = {};
    for(auto it:time){
        int t = it%60;
        int y = (60 - t)%60;
        count += map[y];
        map[t]++;
    }
    return count;
}

int main(){
    int n, value;
    vector<int> time;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        time.push_back(value);
    }
    int result = numPairsDivisibleBy60(time);
    cout << result;
    return 0;
}