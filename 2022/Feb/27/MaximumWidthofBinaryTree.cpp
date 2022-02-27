// https://leetcode.com/problems/maximum-width-of-binary-tree/

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

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode*, unsigned long long int>> q;
    int maxWidth = INT_MIN;
    q.push({root, 0});
    while (!q.empty())
    {
        unsigned long long int left = q.front().second, right = 0;
        int size = q.size();
        while (size-- > 0)
        {
            pair<TreeNode*, unsigned long long int> node = q.front();
            q.pop();
            right = node.second;
            if(node.first->left != nullptr){
                q.push({node.first->left, 2*node.second + 1});
            }
            if(node.first->right != nullptr){
                q.push({node.first->right, 2*node.second + 2});
            }
        }
        maxWidth = max(maxWidth, int(right - left + 1));
    }
    return maxWidth;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->right->right->right = new TreeNode(10);
    // root->left->right->right = new TreeNode(6);
    int result = widthOfBinaryTree(root);
    cout << result;
    return 0;
}