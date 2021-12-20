// https://leetcode.com/problems/max-area-of-island/
#include <bits/stdc++.h>

using namespace std;

// Using BFS
int FindTheIsland(vector<vector<int>> &grid, int row, int col){
    if(row < 0|| row >= grid.size() || col < 0 || col >= grid[0].size()){
        return 0;
    }

    int area = 0;

    if(grid[row][col] == 1){
        grid[row][col] = 0;
        area = 1 + FindTheIsland(grid, row + 1, col) + FindTheIsland(grid, row - 1, col) + FindTheIsland(grid, row, col + 1) + FindTheIsland(grid, row, col - 1);
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int area = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                area = max(area, FindTheIsland(grid, i, j));
            }
        }
    }
    return area;
}

int main(){
    vector<vector<int>> grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int max = maxAreaOfIsland(grid);
    cout << max;
    return 0;
}