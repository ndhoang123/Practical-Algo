// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int countA = 0;
    int countB = 0;
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    while (tempA != nullptr)
    {
        countA++;
    }
    while (tempB != nullptr)
    {
        countB++;
    }
    if(countA > countB){
        for(int i = 0; i < countA - countB; i++){
            headA = headA->next;
        }
    }
    else if(countA < countB){
        for(int i = 0; i < countB - countA; i++){
            headB = headB->next;
        }
    }
    while(headA != nullptr){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

int main(){
    return 0;
}