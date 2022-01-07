// https://leetcode.com/problems/path-sum/

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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL) return false;
    if(targetSum == root->val && root->left == NULL && root->right == NULL) return true;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(3);
    tree->left->left->left = new TreeNode(4);
    tree->left->left->left->left = new TreeNode(5);
    // tree->left->left = new TreeNode(11);
    // tree->left->left->left = new TreeNode(7);
    // tree->left->left->right = new TreeNode(2);
    // tree->right->left = new TreeNode(13);
    // tree->right->right = new TreeNode(4);
    // tree->right->right->right = new TreeNode(1);
    hasPathSum(tree, 6) ? cout << "True" : cout << "False";
    return 0;
}