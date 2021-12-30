// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result(numRows);
    for(int i = 0; i < numRows; i++){
        result[i] = vector<int>(i+1, 1);
        for(int j = 1; j < i; j++){
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}

int main(){
    int numRows;
    cin >> numRows;
    vector<vector<int>> result = generate(numRows);
    for(int i = 0; i < result.size(); i++){
        cout << i << ":";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}