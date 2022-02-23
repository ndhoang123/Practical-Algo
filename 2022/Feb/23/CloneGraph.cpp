// https://leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void bfs(Node *src)
{
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " <<u << "\n";
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

Node *cloneGraph(Node *src)
{
    if(src == nullptr || src->neighbors.empty()) return src;
    map<Node*, Node*> h;
    queue<Node*> q;

    Node* node = new Node();
    node->val = src->val;

    q.push(src);
    h[src] = node;
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        vector<Node*> v = temp->neighbors;
        int n = v.size();
        for(int i = 0; i < n; i++){
            if(h[v[i]] == nullptr){
                node = new Node();
                node->val = v[i]->val;
                h[v[i]] = node;
                q.push(v[i]);
            }
            h[temp]->neighbors.push_back(h[v[i]]);
        }
    }
    return h[src];
}

int main(){
    Node* node1 = new Node();
    node1->val = 1;
    Node* node2 = new Node();
    node2->val = 2;
    Node* node3 = new Node();
    node3->val = 3;
    Node* node4 = new Node();
    node4->val = 4;
    vector<Node*> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbors = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node4->neighbors = v;
    v.clear();
    bfs(node1);
    Node* src = cloneGraph(node1);
    bfs(src);
    return 0;
}