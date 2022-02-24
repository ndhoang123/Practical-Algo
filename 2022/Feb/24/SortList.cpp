// https://leetcode.com/problems/sort-list/

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

ListNode* sortList(ListNode* head)
{
    priority_queue<int> h;
    while (head != nullptr)
    {
        h.push(head->val);
        head = head->next;
    }
    ListNode* result = nullptr;
    while (!h.empty())
    {
        ListNode* temp = new ListNode(h.top());
        h.pop();
        temp->next = result;
        result = temp;
    }
    return result;
}

int main(){
    ListNode* head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    head = sortList(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}