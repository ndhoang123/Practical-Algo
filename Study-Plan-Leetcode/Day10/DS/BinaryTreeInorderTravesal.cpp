// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void treeTraversal(TreeNode *root, vector<int> &result){
    if(root == NULL){
        return;
    }
    treeTraversal(root->left, result);
    result.push_back(root->val);
    treeTraversal(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    treeTraversal(root, result);
    return result;
}

int main(){
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->left->left = new TreeNode(6);
    tree->left->left->right = new TreeNode(7);
    tree->left->right->left = new TreeNode(8);
    tree->right->left = new TreeNode(9);
    vector<int> result = inorderTraversal(tree);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}