// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *connect(Node *root)
{
    if (root == NULL)
        return nullptr;
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            if(i!=n-1) temp->next = q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right); 
        }
    }
    return root;
}

int main()
{
    Node *result;
    Node *root = newNode(1);
    root->left = newNode(2), root->right = newNode(3);
    root->left->left = newNode(4), root->left->right = newNode(5);
    root->right->left = newNode(6), root->right->right = newNode(7);
    result = connect(root);
    queue<Node *> q;
    q.push(result);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->val << " ";
        if(temp->next == NULL){
            cout << 0 << " ";
        }
        else{
            cout << temp->next->val << " ";
        }
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