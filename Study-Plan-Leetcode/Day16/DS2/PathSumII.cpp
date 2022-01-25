// https://leetcode.com/problems/path-sum-ii/

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

void dfs(TreeNode *root, int targetSum, vector<vector<int>> &result, vector<int> &temp, int sum){
    if (root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        sum += root->val;
        if(sum == targetSum){
            temp.push_back(root->val);
            result.push_back(temp);
        }
        return;
    }
    temp.push_back(root->val);
    sum += root->val;
    int sumT = sum;
    vector<int> temp1 = temp;
    dfs(root->left, targetSum, result, temp1, sumT);
    dfs(root->right, targetSum, result, temp, sum);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> result;
    vector<int> temp;
    if(root == nullptr) return result;
    if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
        temp.push_back(root->val);
        result.push_back(temp);
        return result;
    }
    int sum = root->val;
    temp.push_back(root->val);
    dfs(root->left, targetSum, result, temp, sum);
    temp.clear();
    temp.push_back(root->val);
    dfs(root->right, targetSum, result, temp, sum);
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(11);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    // root->right->right->left = new TreeNode(5);
    // root->right->right->right = new TreeNode(1);
    vector<vector<int>> result = pathSum(root, 5);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}