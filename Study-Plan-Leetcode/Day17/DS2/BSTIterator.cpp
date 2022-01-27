// https://leetcode.com/problems/binary-search-tree-iterator/

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

class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* root){
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    cout << param_1 << " ";
    bool param_2 = obj->hasNext();
    param_2 ? cout << "True": cout << "False";
    return 0;
}