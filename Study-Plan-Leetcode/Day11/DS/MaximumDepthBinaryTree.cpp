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

int maxDepth(TreeNode *root)
{
    if(root == NULL) return 0;
    queue<TreeNode *> q;
    int maxNode = 0, it = 1, count = 0;
    q.push(root);
    while (!q.empty())
    {
        ++maxNode;
        for (int i = 0; i < it; i++)
        {
            TreeNode *q1 = q.front();
            q.pop();
            if (q1->left != NULL)
            {
                q.push(q1->left);
                count++;
            }
            if (q1->right != NULL)
            {
                q.push(q1->right);
                count++;
            }
        }
        it = count;
        count = 0;
    }
    return maxNode;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->right = new TreeNode(20);
    int val = maxDepth(tree);
    cout << val;
    return 0;
}