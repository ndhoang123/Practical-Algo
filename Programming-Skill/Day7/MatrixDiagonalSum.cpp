// https://leetcode.com/problems/matrix-diagonal-sum/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int sum = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        if (i == mat.size() - i - 1)
            sum += mat[i][i];
        else
            sum += mat[i][i] + mat[i][mat.size() - 1 - i];
    }
    return sum;
}

int main()
{
    int res;
    vector<vector<int>> mat = {{5}};
    res = diagonalSum(mat);
    cout << res;
    return 0;
}