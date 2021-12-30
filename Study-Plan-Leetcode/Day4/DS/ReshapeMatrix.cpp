// https://leetcode.com/problems/reshape-the-matrix/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int rows = mat.size(), cols = mat[0].size(), r1 = 0, c1 = 0;
    if(rows*cols != r*c) return mat;
    vector<vector<int>> result(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(c1 == cols){
                r1++;
                c1 = 0;
            }
            result[i][j] = mat[r1][c1++];
        }
    }
    return result;
}

int main(){
    vector<vector<int>> mat{
        {1, 2, 5},
        {3, 4, 6}
    };
    vector<vector<int>> result = matrixReshape(mat, 3, 2);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << i << " " << j << ":" << result[i][j] << endl;
        }
    }
    return 0;
}