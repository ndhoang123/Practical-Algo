// https://leetcode.com/problems/keys-and-rooms/

#include <bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    unordered_set<int> seen;
    seen.insert(0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int nextRoom : rooms[u])
        {
            if (seen.count(nextRoom))
                continue;
            seen.insert(nextRoom);
            q.push(nextRoom);
        }
    }
    return seen.size() == n;
}

int main()
{
    vector<vector<int>> rooms{{2}, {}, {1}};
    canVisitAllRooms(rooms) ? cout << "True" : cout << "False";
    return 0;
}