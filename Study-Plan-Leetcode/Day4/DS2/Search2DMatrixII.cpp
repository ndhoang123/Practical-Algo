// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if(matrix.empty()) return false;
    int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = col - 1;
    while(left < row && right >= 0){
        if(matrix[left][right] == target){
            return true;
        }
        if(matrix[left][right] > target){
            right--;
        }
        else{
            left++;
        }
    }
    return false;
}

int main(){
    // vector<vector<int>> matrix{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, 
    // {10,13,14,17,24}, {18,21,23,26,30}};
    vector<vector<int>> matrix{{-5}};
    int target;
    cin >> target;
    searchMatrix(matrix, target) ? cout << "True" : cout << "False";
    return 0;
}