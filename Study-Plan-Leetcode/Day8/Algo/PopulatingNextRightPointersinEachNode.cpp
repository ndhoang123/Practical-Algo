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
    queue<Node *> q1, q2;
    int n = 0;
    q1.push(root);
    q2.push(root);
    while (!q1.empty())
    {
        Node *temp = q1.front();
        q1.pop();
        if (temp->left != NULL && temp->right != NULL)
        {
            q1.push(temp->left);
            q2.push(temp->left);
            q1.push(temp->right);
            q2.push(temp->right);
        }
    }
    while (!q2.empty())
    {
        Node *temp;
        if (n == 0)
        {
            temp = q2.front();
            q2.pop();
            temp->next = NULL;
        }
        else
        {
            for (int i = 1; i <= pow(2, n); i++)
            {
                if (i == pow(2, n))
                {
                    temp->next = q2.front();
                    temp = q2.front();
                    temp->next = NULL;
                    q2.pop();
                }
                if (i == 1)
                {
                    temp = q2.front();
                    q2.pop();
                }
                if (i > 1 && i < pow(2, n))
                {
                    temp->next = q2.front();
                    temp = q2.front();
                    q2.pop();
                }
            }
        }
        n++;
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