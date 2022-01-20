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
    ListNode *tempA = headA;
    ListNode* tempB = headB;
    while(tempA != nullptr && tempB != nullptr && tempA != tempB){
        tempA = tempA->next;
        tempB = tempB->next;
        if(tempA == tempB) return tempA;
        if(tempA == nullptr) tempA = headB;
        if(tempB == nullptr) tempB = headA;
    }
    return tempA;
}

int main(){
    return 0;
}