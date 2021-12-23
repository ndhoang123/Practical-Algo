// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        if (temp->next != NULL && temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return head;
}

int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *head3 = NULL;
    ListNode *temp1 = head1;
    temp1->next = new ListNode(1);
    temp1 = temp1->next;
    temp1->next = new ListNode(2);
    temp1 = temp1->next;
    temp1->next = new ListNode(3);
    temp1 = temp1->next;
    temp1->next = new ListNode(4);
    temp1 = temp1->next;
    temp1->next = new ListNode(4);
    head3 = deleteDuplicates(head1);
    return 0;
}