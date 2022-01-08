// https://leetcode.com/problems/search-in-a-binary-search-tree/

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

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return nullptr;
    if(root->val == val) return root;
    if(root->val < val){
        return searchBST(root->left, val);
    }
    else{
        return searchBST(root->right, val);
    }
}

void treeTravesal(TreeNode* tree){
    queue<TreeNode*> q;
    q.push(tree);
    while(!q.empty()){
        tree = q.front();
        q.pop();
        cout << tree->val << " ";
        if(tree->left != NULL){
            q.push(tree->left);
        }
        if(tree->right != NULL){
            q.push(tree->right);
        }
    }
}

int main(){
    TreeNode* tree = new TreeNode(4);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(3);
    tree = searchBST(tree, 5);
    if(tree == nullptr){
        cout << 0;
    }
    else{
        treeTravesal(tree);
    }
    return 0;
}