// https://www.topcoder.com/thrive/articles/Greedy%20is%20Good
// Implementation of Greedy algorithm based on the pseucode in the above link

#include <bits/stdc++.h>

using namespace std;

int comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int greedyImplementation(vector<vector<int>> &a){
    sort(a.begin(), a.end(), comp);
    int count = 1;
    int lastChosen = 0;
    for(int i = 1; i < a.size(); i++){
        if(a[i][0] >= a[lastChosen][1]){
            ++count;
            lastChosen = i;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> activies{{36, 722}, {311, 321}, {319, 323}, {415, 515}, {510, 516}, {712, 714}, {721, 860}};
    int result = greedyImplementation(activies);
    cout << result;
    return 0;
}