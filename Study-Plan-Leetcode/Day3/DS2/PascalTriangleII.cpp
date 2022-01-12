// https://leetcode.com/problems/pascals-triangle-ii/

#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int rowIndex)
{
    int tempVal = rowIndex + 1;
    vector<vector<int>> temp(tempVal);
    for (size_t i = 0; i < rowIndex + 1; i++)
    {
        temp[i] = vector<int>(i+1, 1);
        for (size_t j = 1; j < i; j++)
        {
            temp[i][j] = temp[i-1][j-1] + temp[i-1][j];
        }
    }
    return temp[rowIndex];
}

int main(){
    int rowIndex;
    cin >> rowIndex;
    vector<int> result = getRow(rowIndex);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}