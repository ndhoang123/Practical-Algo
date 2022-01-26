// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

int kthSmallest(TreeNode *root, int k)
{
    queue<TreeNode*> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        v.push_back(temp->val);
        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }
    sort(v.begin(), v.end());
    return v[k-1];
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int result = kthSmallest(root, 1);
    cout << result;
    return 0;
}