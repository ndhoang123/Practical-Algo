// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void travel(Node *root, vector<int> &vt)
{
    if (root == nullptr)
    {
        return;
    }
    vt.push_back(root->val);
    for (Node *child : root->children)
    {
        travel(child, vt);
    }
}

vector<int> preorder(Node *root)
{
    vector<int> result;
    travel(root, result);
    return result;
}

int main()
{
    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    vector<int> rs = preorder(root);
    for(int i = 0; i < rs.size(); i++)
    {
        cout << rs[i] << " ";
    }
    return 0;
}