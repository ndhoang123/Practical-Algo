// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n; i++) // Have to use this condition to handle index of Nth node from last.
    {
        fast = fast->next;
    }
    if (fast == NULL) // If fast equal null, and n. Have to remove the first head.
    {
        return head->next;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head; // Return the head, to obtain the value.
}
