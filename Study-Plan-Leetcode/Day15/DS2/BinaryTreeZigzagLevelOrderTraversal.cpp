// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    bool isAlternative = false;
    int count = 1, countT = 0;
    int it = 0;
    queue<TreeNode*> q;
    if(root == nullptr) return result;
    if(root->left == nullptr && root->right == nullptr){
        result.push_back(vector<int>(1, root->val));
        return result;
    }
    q.push(root);
    while(!q.empty()){
        countT = 0;
        result.push_back(vector<int>());
        for(int i = 0; i < count; i++){
            TreeNode *temp = q.front();
            q.pop();
            result[it].push_back(temp->val);
            if(temp->left != nullptr){
                q.push(temp->left);
                countT++;
            }
            if(temp->right != nullptr){
                q.push(temp->right);
                countT++;
            }
        }
        if(isAlternative == true){
            isAlternative = false;
            reverse(result[it].begin(), result[it].end());
        }
        else{
            isAlternative = true;
        }
        count = countT;
        it++;
    }
    return result;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = zigzagLevelOrder(root);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}