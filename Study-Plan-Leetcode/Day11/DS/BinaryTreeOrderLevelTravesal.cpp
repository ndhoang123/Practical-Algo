// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if(root == NULL) return result;
    int count = 0, it = 1, i = 0;
    queue<TreeNode*> q;
    vector<int> r;
    q.push(root);
    while(!q.empty()){
        r.clear();
        for(int j = 0; j < it; j++){
            TreeNode *temp = q.front();
            q.pop();
            r.push_back(temp->val);
            if(temp->left != NULL){
                count++;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                count++;
                q.push(temp->right);
            }
        }
        it = count;
        count = 0;
        ++i;
        result.push_back(r);
    }
    return result;
}

int main(){
    vector<vector<int>> result;
    TreeNode* tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    result = levelOrder(tree);
    for(int i = 0; i < result.size(); i++){
        for(auto it : result[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}