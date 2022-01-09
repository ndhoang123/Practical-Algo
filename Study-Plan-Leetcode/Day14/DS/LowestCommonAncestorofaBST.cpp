// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root->val > q->val && root->val > p->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    if(root->val < q->val && root->val < p->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}



int main(){
    TreeNode* tree = new TreeNode(6);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(8);
    tree->left->left = new TreeNode(0);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(7);
    tree->right->right = new TreeNode(9);
    tree->left->right->left = new TreeNode(3);
    tree->left->right->right = new TreeNode(5);
    TreeNode* temp = tree;
    temp = lowestCommonAncestor(tree, tree->left, tree->left->right);
    cout << temp->val;
    return 0;
}