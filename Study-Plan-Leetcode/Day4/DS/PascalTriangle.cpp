// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    int cal = 0;
    for(int i = 1; i <= numRows; i++){
        vector<int> temp;
        for(int j = 0; j < i; j++){
            if(j == 0 || j == i - 1){
                temp.push_back(1);
            }
            else{
                cal = result[i-2][j-1] + result[i-2][j];
                temp.push_back(cal);
            }
        }
        result.push_back(temp);
    }
    return result;
}

int main(){
    int numRows;
    cin >> numRows;
    vector<vector<int>> result = generate(numRows);
    return 0;
}