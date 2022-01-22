// https://leetcode.com/problems/reorder-list/

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

ListNode* findMiddle(ListNode *head){
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode *head){
    ListNode *prev = nullptr;
    while(head != nullptr){
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    if(!head->next) return;
    ListNode* middle = findMiddle(head);
    ListNode* R = reverseList(middle);
    ListNode* L = head->next;
    ListNode* temp = head;
    for(int i = 0; L != R; i++, temp = temp->next){
        if(i == 0 || i % 2 == 0){
            temp->next = R;
            R = R->next;
        }
        else{
            temp->next = L;
            L = L->next;
        }
    }
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    reorderList(head);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}