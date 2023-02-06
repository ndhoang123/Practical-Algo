// https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    for(int i = 0; i < coordinates.size(); i++)
    {
        if((coordinates[i][1] - coordinates[0][1])*dx != (coordinates[i][0] - coordinates[0][0])*dy){
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> coordinates = {{2,4},{2,5},{2,8}};
    checkStraightLine(coordinates) ? cout << "true" : cout << "false";
    return 0;
}