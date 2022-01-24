// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.empty())
    {
        return nullptr;
    }
    if (nums.size() == 1)
    {
        return new TreeNode(nums[0]);
    }
    int middle = (nums.size()) / 2;
    vector<int> l(nums.begin(), nums.begin() + middle);
    vector<int> r(nums.begin() + middle + 1, nums.end());
    return new TreeNode(nums[middle], sortedArrayToBST(l), sortedArrayToBST(r));
}

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
    vector<int> nums{1, 3}; //-10,-3,0,5,9
    TreeNode *result = sortedArrayToBST(nums);
    treeTraversal(result);
    // cout << (nums.size()-1)/2 << " ";
    // vector<int>left(nums.begin(), nums.begin() + (nums.size()-1)/2);
    // for(auto it : left){
    //     cout << it << " ";
    // }
    return 0;
}