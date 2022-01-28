// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <bits/stdc++.h>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    unordered_set<int> head;
    unordered_set<int> tail;
    vector<int> result;
    for (int i = 0; i < edges.size(); i++)
    {
        if(head.find(edges[i][0]) == head.end() && tail.find(edges[i][0]) == tail.end()){
            head.insert(edges[i][0]);
        }
        if(tail.find(edges[i][1]) == tail.end()){
            if(head.find(edges[i][1]) != head.end()){
                head.erase(edges[i][1]);
            }
            tail.insert(edges[i][1]);
        }
    }
    for (auto it : head)
    {
        result.push_back(it);
    }
    return result;
}

int main(){
    vector<vector<int>> edges{{0,1}, {2,1}, {3,1}, {1,4}, {2,4}};
    vector<int> result = findSmallestSetOfVertices(6, edges);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}