// https://leetcode.com/problems/binary-tree-preorder-traversal/
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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> st;
    if(root == NULL) return result;
    st.push(root);
    while(!st.empty()){
        TreeNode* value = st.top();
        result.push_back(value->val);
        st.pop();
        if(value->right != NULL) st.push(value->right);
        if(value->left != NULL) st.push(value->left);
    }
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
    vector<int> result = preorderTraversal(tree);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}