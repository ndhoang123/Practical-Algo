// https://leetcode.com/problems/add-two-numbers/

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL && l2 != NULL) return l2;
    if(l1 != NULL && l2 == NULL) return l1;
    int reminder = 0;
    int temp = 0;
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    while(t1 != NULL || t2 != NULL){
        if(t1 != NULL && t2 != NULL){
            temp = t1->val + t2->val + reminder;
            t1->val = temp % 10;
            reminder = temp / 10;
            if(t1->next != NULL && t2->next == NULL){
                t2->next = new ListNode(0);
            }
            else if(t1->next == NULL && t2->next != NULL){
                t1->next = new ListNode(0);
            }
            else if(t1->next == NULL && t2->next == NULL && reminder > 0){
                t1->next = new ListNode(reminder);
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return l1;
}

int main(){
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);
    // l1->next->next->next = new ListNode(9);
    // l1->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next->next = new ListNode(9);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);
    // l2->next->next->next = new ListNode(9);
    ListNode *temp = addTwoNumbers(l1, l2);
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}