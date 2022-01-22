// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
        if(cursor == nullptr) return head;
        cursor = cursor->next;
    }

    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    for(int i = 0; i < k; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    int k;
    cin >> k;
    ListNode *result = reverseKGroup(head, k);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}