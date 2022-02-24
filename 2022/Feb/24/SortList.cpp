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

ListNode* getMid(ListNode* head){
    ListNode* midPrev = nullptr;
    while (head != nullptr && head->next != nullptr)
    {
        midPrev = midPrev == nullptr ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* dummyhead = new ListNode(0);
    ListNode* temp = dummyhead;
    while (l1 != nullptr && l2 != nullptr)
    {
        cout << l1->val << " " << l2->val << endl;
        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    temp->next = (l1) ? l1 : l2;
    return dummyhead->next;
}

ListNode* sortList(ListNode* head)
{
    if(!head || !head->next){
        return head;
    }
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
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