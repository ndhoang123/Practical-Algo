// https://leetcode.com/problems/merge-two-sorted-lists/

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(list1 != NULL && list2 == NULL) return list1;
    if(list1 == NULL && list2 != NULL) return list2;
    if(list1 == NULL && list2 == NULL) return NULL;
    ListNode *list3 = NULL;
    ListNode *list4 = NULL;
    if(list1->val <= list2->val){
        list3 = list1;
        list4 = list3;
        list1 = list1->next;
    }
    else if(list1->val > list2->val){
        list3 = list2;
        list4 = list3;
        list2 = list2->next;
    }
    while(list1 != NULL || list2 != NULL){
        if(list1->val <= list2->val || (list1 != NULL && list2 == NULL)){
            list3->next = list1;
            list1 = list1->next;
        }
        if(list1->val > list2->val || (list2 != NULL && list1 == NULL)){
            list3->next = list2;
            list2 = list2->next;
        }
        list3 = list3->next;
    }
    return list3;
}

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(1);
    ListNode* head3 = NULL;
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    temp1->next = new ListNode(2);
    temp2->next = new ListNode(3);
    temp1 = temp1->next;
    temp2 = temp2->next;
    temp1->next = new ListNode(4);
    temp2->next = new ListNode(4);
    head3 = mergeTwoLists(head1, head2);
    return 0;
}