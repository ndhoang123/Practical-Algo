// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>> &points)
{
    int loc = -1, dis = INT_MAX;
    for(int i = 0; i < points.size(); i++){
        if(x == points[i][0] || y == points[i][1]){
            if(abs(x - points[i][0]) + abs(y - points[i][1]) < dis){
                loc = i;
                dis = abs(x - points[i][0]) + abs(y - points[i][1]);
            }
        }
    }
    return loc;
}

int main()
{
    int x = 3, y = 4, res;
    vector<vector<int>> points = {{3,4}};
    res = nearestValidPoint(x, y, points);
    cout << res;
    return 0;
}