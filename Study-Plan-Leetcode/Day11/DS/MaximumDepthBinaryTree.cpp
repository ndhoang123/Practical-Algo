// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

int maxDepth(TreeNode *root)
{
    if(root == NULL){
        return 0;
    }
    int left_node = maxDepth(root->left) + 1;
    int right_node = maxDepth(root->right) + 1;
    return left_node > right_node ? left_node : right_node;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->right = new TreeNode(20);
    int val = maxDepth(tree);
    cout << val;
    return 0;
}