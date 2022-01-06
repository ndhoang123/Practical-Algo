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

bool isSymmetric(TreeNode *root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
    if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) return false;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() && !q2.empty()){
        TreeNode* temp1 = q1.front();
        TreeNode* temp2 = q2.front();
        q1.pop();
        q2.pop();
        cout << temp1->val << " " << temp2->val << endl;
        if((temp1->left != NULL && temp2->right == NULL) || (temp1->left == NULL && temp2->right != NULL)){
            cout << "B:" << temp1->val << " " << temp2->val;
            return false;
        }
        if((temp1->right != NULL && temp2->left == NULL) || (temp1->right == NULL && temp2->left != NULL)){
            cout << "C:" << temp1->val << " " << temp2->val;
            return false;
        }
        if(temp1->val != temp2->val){
            cout << "A:" << temp1->val << " " << temp2->val;
            return false;
        }
        if(temp1->left != NULL && temp2->right != NULL){
            q1.push(temp1->left);
            q2.push(temp2->right);
        }
        if(temp1->right != NULL && temp2->left != NULL){
            q1.push(temp1->right);
            q2.push(temp2->left);
        }
    }
    return true;
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