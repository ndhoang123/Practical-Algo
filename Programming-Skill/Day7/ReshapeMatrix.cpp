// https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int rows = mat.size(), cols = mat[0].size(), total = rows * cols;
    if (rows * cols != r * c)
        return mat;
    vector<vector<int>> result(r, vector<int>(c));
    for (int i = 0; i < total; i++)
    {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }
    return result;
}

int main()
{
    vector<vector<int>> mat = {};
    vector<vector<int>> res = matrixReshape(mat, 1, 4);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res.size(); j++){
            cout << res[i] << " ";
        }
    }
    return 0;
}