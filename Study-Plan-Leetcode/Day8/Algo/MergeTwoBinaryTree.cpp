// https://leetcode.com/problems/merge-two-binary-trees/
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

TreeNode *newNode(int data)
{
    TreeNode *temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    if (!root1 || !root2) return root1 ? root1 : root2;
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root1, root2});
    while (!q.empty())
    {
        TreeNode *temp1, *temp2;
        temp1 = q.front().first;
        temp2 = q.front().second;
        q.pop();
        temp1->val = temp1->val + temp2->val;
        if (temp1->left != NULL && temp2->left != NULL)
        {
            q.push({temp1->left, temp2->left});
        }
        if (temp1->right != NULL && temp2->right != NULL)
        {
            q.push({temp1->right, temp2->right});
        }
        if (temp1->left == NULL && temp2->left != NULL)
        {
            temp1->left = temp2->left;
        }
        if (temp1->right == NULL && temp2->right != NULL)
        {
            temp1->right = temp2->right;
        }
    }
    return root1;
}

int main()
{
    /*
    TreeNode *root1 = newNode(1), *root2 = newNode(2);
    root1->left = newNode(3), root2->left = newNode(1);
    root1->right = newNode(2), root2->right = newNode(3);
    root1->left->left = newNode(5), root2->left->right = newNode(4);
    root1->left->right = NULL, root2->left->left = NULL;
    root2->right->right = newNode(7);
    */
    TreeNode* result;
    TreeNode* root1 = newNode(1), *root2 = NULL;

    result = mergeTrees(root1, root2);
    queue<TreeNode *> q;
    q.push(result);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        cout << temp->val << " ";
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    return 0;
}