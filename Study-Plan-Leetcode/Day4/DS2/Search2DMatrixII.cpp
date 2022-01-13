// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if(matrix.empty()) return false;
    int left, right;
    int row = matrix.size(), col = matrix[0].size();
    for(int i = 0; i < row; i++){
        left = 0;
        right = col-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(matrix[i][mid] == target){
                return true;
            }
            if(matrix[i][mid] < target){
                left = mid + 1;
            }
            else if(matrix[i][mid] > target){
                right = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, 
    {10,13,14,17,24}, {18,21,23,26,30}};
    int target;
    cin >> target;
    searchMatrix(matrix, target) ? cout << "True" : cout << "False";
    return 0;
}