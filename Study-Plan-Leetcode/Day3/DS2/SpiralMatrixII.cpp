// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n));
    int colS = 0, colE = n-1;
    int rowS = 0, rowE = n-1;
    int cnt = 1;
    while (colS <= colE && rowS <= rowE)
    {
        for(int i = colS; i <= colE; i++){
            result[rowS][i] = cnt++;
        }
        rowS++;
        
        for(int i = rowS; i <= rowE; i++){
            result[i][colE] = cnt++;
        }
        colE--;

        for (int i = colE; i >= colS; i--)
        {
            result[rowE][i] = cnt++;
        }
        rowE--;
        
        for (int i = rowE; i >= rowS; i--)
        {
            result[i][colS] = cnt++;
        }
        colS++;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> result = generateMatrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
    }
    return 0;
}