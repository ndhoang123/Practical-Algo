// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

#include <bits/stdc++.h>

using namespace std;

class Tuple{
    public:
        int node;
        int mask;
        int cost;
        Tuple(int node, int mask, int cost){
            this->mask = mask;
            this->node = node;
            this->cost = cost;
        }
};

int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();
    queue<Tuple> q;
    set<pair<int, int>> vis;

    int all = (1 << n) - 1;
    for(int i = 0; i < n; i++){
        int maskValue = (1 << i);

        Tuple thisNode(i, maskValue, 1);

        q.push(thisNode);

        vis.insert({i, maskValue});
    }

    while (!q.empty())
    {
        Tuple curr = q.front();
        q.pop();

        if(curr.mask == all){
            return curr.cost - 1;
        }

        for(auto &adj : graph[curr.node]){
            int bothVisitedMask = curr.mask;

            bothVisitedMask = bothVisitedMask | (1 << adj);

            Tuple thisNode(adj, bothVisitedMask, curr.cost + 1);

            if(vis.find({adj, bothVisitedMask}) == vis.end()){
                vis.insert({adj, bothVisitedMask});

                q.push(thisNode);
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> graph{{1}, {0,2,4}, {1,3,4}, {2}, {1, 2}};
    int result = shortestPathLength(graph);
    cout << result;
    return 0;
}