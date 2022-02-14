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

int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    queue<TreeNode*> q;
    int maxDepth = 0, it = 1, count = 0;
    q.push(root);
    while (!q.empty())
    {
        ++maxDepth;
        for(int i = 0; i < it; i++){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left != nullptr){
                count++;
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                count++;
                q.push(temp->right);
            }
        }
        it = count;
        count = 0;
    }
    return maxDepth;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int result = maxDepth(root);
    cout << result;
    return 0;
}