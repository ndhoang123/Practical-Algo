// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;

    stack<Node *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        Node *cur = stk.top();
        stk.pop();
        result.push_back(cur->val);
        for (int i = cur->children.size() - 1; i >= 0; i--)
        {
            if (cur->children[i] != nullptr)
            {
                stk.push(cur->children[i]);
            }
        }
    }
    return result;
}

int main()
{
    Node *root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    vector<int> rs = preorder(root);
    for (int i = 0; i < rs.size(); i++)
    {
        cout << rs[i] << " ";
    }
    return 0;
}