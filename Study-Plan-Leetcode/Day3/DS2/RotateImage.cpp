// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)n / 2; j++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Original array:";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (auto it : matrix[i])
        {
            cout << it << " ";
        }
    }
    cout << endl;
    rotate(matrix);
    cout << "Rotated array:";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (auto it : matrix[i])
        {
            cout << it << " ";
        }
    }
    return 0;
}