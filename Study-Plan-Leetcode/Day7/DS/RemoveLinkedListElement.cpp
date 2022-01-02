// https://leetcode.com/problems/remove-linked-list-elements/

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    while (head != nullptr && head->val == val)
    {
        head = head->next;
    }
    ListNode *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(7);
    ListNode *temp = head;
    temp->next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(7);
    temp = temp->next;
    temp->next = new ListNode(7);
    temp = temp->next;
    head = removeElements(head, 7);
    head == NULL ? cout << 0 : cout << "False";
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}