// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

class Solution
{
private:
    int preIdx = 0;
    unordered_map<int, int> h;
    TreeNode *dfs(vector<int> &preorder, int l, int r)
    {
        if (l > r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preIdx++]);
        int mid = h[root->val];
        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            h[inorder[i]] = i;
        }
        return dfs(preorder, 0, n-1);
    }
};

void treeTraversal(TreeNode *result)
{
    queue<TreeNode *> q;
    q.push(result);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution *result = new Solution();
    TreeNode* temp = result->buildTree(preorder, inorder);
    treeTraversal(temp);
    return 0;
}