// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size(), c = matrix[0].size(), row = 0, left = 0, right = c - 1, down = r - 1;
    if(target < matrix[0][0] || target > matrix[r-1][c-1]) return false;
    while(row <= down){
        int mid = (row + down) / 2;
        if(matrix[mid][0] == target || matrix[mid][right] == target){
            return true;
        }
        if(matrix[mid][0] > target){
            down = mid - 1;
        }
        if(matrix[mid][0] < target && target > matrix[mid][right]){
            row = mid + 1;
        }
        if(matrix[mid][0] < target && target < matrix[mid][right]){
            row = mid;
            break;
        }
    }
    while(left <= right){
        int mid = (left+right) / 2;
        if(target == matrix[row][mid]){
            return true;
        }
        if(target > matrix[row][mid]){
            left = mid + 1;
        }
        if(target < matrix[row][mid]){
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    searchMatrix(matrix, 34) ? cout << "True" : cout << "False";
    return 0;
}