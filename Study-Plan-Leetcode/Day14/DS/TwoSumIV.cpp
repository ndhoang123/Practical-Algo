// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

bool findTarget(TreeNode* root, int k) {
    if(root == NULL) return false;
    queue<TreeNode*> q;
    unordered_set<int> h;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(h.find(k-temp->val) != h.end()){
            return true;
        }
        else{
            h.insert(temp->val);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    return false;
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(6);
    tree->left->left = new TreeNode(2);
    tree->left->right = new TreeNode(4);
    tree->right->right = new TreeNode(7);
    findTarget(tree, 28) ? cout << "Found" : cout << "Not found";
    return 0;
}