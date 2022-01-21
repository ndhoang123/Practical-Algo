// https://leetcode.com/problems/swap-nodes-in-pairs/

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

ListNode *swapPairs(ListNode *head)
{
    if(head == nullptr) return head;
    int tempVal;
    ListNode* result = head;
    while(result != nullptr){
        if(result->next != nullptr){
            tempVal = result->val;
            result->val = result->next->val;
            result->next->val = tempVal;
            result = result->next->next;
        }
        else if(result->next == nullptr){
            result = result->next;
        }
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    ListNode* value = swapPairs(head);
    while(value != nullptr){
        cout << value->val << " ";
        value = value->next;
    }
    return 0;
}