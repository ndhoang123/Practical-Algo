// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL){
        root = new TreeNode(val);
        return root;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->val < val){
            if(temp->right != NULL){
                q.push(temp->right);
            }
            else{
                temp->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(temp->left != NULL){
                q.push(temp->left);
            }
            else{
                temp->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
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
    tree = insertIntoBST(tree, 5);
    treeTravesal(tree);
    return 0;
}