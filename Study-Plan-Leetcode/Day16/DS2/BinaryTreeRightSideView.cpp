// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int level, vector<int> &v){
    if(root == nullptr) return;
    if(v.size() < level) v.push_back(root->val);
    dfs(root->right, level+1, v);
    dfs(root->left, level+1, v);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    dfs(root, 1, result);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    // root->right->right = new TreeNode(4);
    vector<int> result = rightSideView(root);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}