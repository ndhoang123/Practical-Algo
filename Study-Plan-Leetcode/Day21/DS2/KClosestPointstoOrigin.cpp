// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> result;
    int n = points.size()-1;
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> he;
    for(int i = 0; i < points.size(); i++){
        cout << points[i][0] << " " << points[i][1] << endl;
        float temp = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        cout << temp << endl;
        he.push(make_pair(temp, i));
    }
    for(int i = 0; i < k; i++){
        result.push_back(vector<int>(2));
        result[i][0] = points[he.top().second][0];
        result[i][1] = points[he.top().second][1];
        he.pop();
    }
    return result;
}

int main(){
    vector<vector<int>> points{{-5, 4}, {-6, -5}, {4, 6}};
    vector<vector<int>> result = kClosest(points, 2);
    for(auto it : result){
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}