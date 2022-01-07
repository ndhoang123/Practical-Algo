// https://leetcode.com/problems/invert-binary-tree/

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

TreeNode *invertTree(TreeNode *root)
{
    if(root == NULL) return root;
    TreeNode* result = new TreeNode();
    queue<TreeNode*> q;
    queue<TreeNode*> q1;
    q.push(root);
    q1.push(result);
    while(!q.empty()){
        TreeNode* temp1 = q.front();
        TreeNode* temp2 = q1.front();
        q.pop();
        q1.pop();
        temp2->val = temp1->val;
        if(temp1->left != NULL){
            q.push(temp1->left);
            temp2->right = new TreeNode();
            q1.push(temp2->right);
        }
        if(temp1->right != NULL){
            q.push(temp1->right);
            temp2->left = new TreeNode();
            q1.push(temp2->left);
        }
    }
    return result;
}

void treeTravesal(TreeNode *tree){
    queue<TreeNode*> q;
    q.push(tree);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int main(){
    TreeNode* temp = NULL;
    TreeNode* tree = new TreeNode(4);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(3);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(9);
    // treeTravesal(tree);
    // cout << endl;
    temp = invertTree(tree);
    treeTravesal(temp);
    return 0;
}