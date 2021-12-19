// https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int rows = image.size(), cols = image[0].size(), oldColor = image[sr][sc];
    if(newColor == oldColor) return image;
    queue<pair<int, int>> q;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    q.push({sr, sc});
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        image[r][c] = newColor;
        for(auto d:dir){
            int rr = r + d[0];
            int cc = c + d[1];
            if(rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;
            if(image[rr][cc] != oldColor) continue;
            q.push({rr, cc});
        }
    }
    return image;
}