// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <bits/stdc++.h>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    // The non in-degree element will be returned. Because non in-degree will not from the other. Otherwise,
    // the in-degree may from the other element. Hence, all non in-degree will be returned in our solution.
    vector<int> result, seen(n);
    for(auto it : edges){
        seen[it[1]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if(seen[i] == 0){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> edges{{0,1}, {2,1}, {3,1}, {1,4}, {2,4}};
    vector<int> result = findSmallestSetOfVertices(5, edges);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}