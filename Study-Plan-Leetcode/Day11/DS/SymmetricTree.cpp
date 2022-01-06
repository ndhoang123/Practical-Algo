// https://leetcode.com/problems/symmetric-tree/

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

bool helper(TreeNode *root1, TreeNode *root2){
    if(!root1 && !root2){
        return true;
    }

    if(!root1 || !root2){
        return false;
    }

    if(root1->val != root2->val){
        return false;
    }

    return helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root)
{
    if(!root) return true;
    return helper(root->left, root->right);
}

int main(){
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left = new TreeNode(5);
    tree->right->right = new TreeNode(4);
    isSymmetric(tree) ? cout << "True" : cout << "False";
    return 0;
}