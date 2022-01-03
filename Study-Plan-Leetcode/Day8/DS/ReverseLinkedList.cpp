// https://leetcode.com/problems/reverse-linked-list/

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

ListNode *reverseList(ListNode *head)
{
    if(head == nullptr) return head;
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(curr != NULL){
        curr = curr->next;
        head->next = prev;
        prev = head;
        if(curr != NULL){
            head = curr;
        }
    }
    return head;
}

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* temp1 = head1;
    temp1->next = new ListNode(2);
    temp1 = temp1->next;
    temp1->next = new ListNode(4);
    ListNode* temp2 = head1;
    cout << "Original list: ";
    while(temp2 != NULL){
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
    cout << "\nNew List:";
    reverseList(head1);
    return 0;
}