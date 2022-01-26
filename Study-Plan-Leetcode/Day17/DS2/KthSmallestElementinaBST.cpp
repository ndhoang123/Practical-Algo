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
    stack<TreeNode*> st;
    while (true)
    {
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if(--k == 0) return root->val;
        root = root->right;
    }
}
// TC: O(H + k), SC: O(H)

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int result = kthSmallest(root, 1);
    cout << result;
    return 0;
}