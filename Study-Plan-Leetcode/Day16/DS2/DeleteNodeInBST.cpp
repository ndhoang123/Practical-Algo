// https://leetcode.com/problems/delete-node-in-a-bst/

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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root == nullptr || (root->left == nullptr && root->right == nullptr && root->val == key)) return nullptr;
    TreeNode* temp = root;
    TreeNode* tempVal = nullptr;
    TreeNode* lastPosition = nullptr;
    char pos;
    while(temp != nullptr){
        if(temp->val == key){
            if(temp->left == nullptr && temp->right == nullptr){
                if(pos == 'l'){
                    lastPosition->left = nullptr;
                    break;
                }
                if(pos == 'r'){
                    lastPosition->right = nullptr;
                    break;
                }
            }
            if(temp->left == nullptr && temp->right != nullptr ||
                temp->right == nullptr && temp->left != nullptr){
                if(lastPosition == nullptr){
                    root = temp->right != nullptr ? temp->right : temp->left;
                    break;
                }
                else{
                    if(pos == 'l'){
                        lastPosition->left = temp->right != nullptr ? temp->right : temp->left;
                        break;
                    }
                    if(pos == 'r'){
                        lastPosition->right = temp->right != nullptr ? temp->right : temp->left;
                        break;
                    }
                }
            }
            if(temp->left != nullptr && temp->right != nullptr){
                tempVal = temp->left;
                if(lastPosition == nullptr){
                    root = temp->right;
                    temp = temp->right;
                    break;
                }
                else{
                    if(pos == 'l'){
                        lastPosition->left = temp->right;
                        temp = lastPosition->left;
                        break;
                    }
                    if(pos == 'r'){
                        lastPosition->right = temp->right;
                        temp = lastPosition->right;
                        break;
                    }
                }
            }
        }
        else{
            if(temp->val < key){
                lastPosition = temp;
                pos = 'r';
                temp = temp->right;
            }
            else{
                lastPosition = temp;
                pos = 'l';
                temp = temp->left;
            }
        }
    }
    if(tempVal != nullptr){
        while (temp != nullptr)
        {
            if(temp->left != nullptr){
                temp = temp->left;
            }
            if(temp->left == nullptr){
                temp->left = tempVal;
                break;
            }
        }
    }
    return root;
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

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    TreeNode* result = deleteNode(root, 7);
    treeTraversal(result);
    return 0;
}