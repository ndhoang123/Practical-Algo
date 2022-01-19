// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    if(!head) return nullptr;
    unordered_set<ListNode*> h;
    ListNode *temp = head;
    while(temp->next){
        if(h.find(temp) == h.end()){
            h.insert(temp);
            temp = temp->next;
        }
        else{
            return temp;
        }
    }
    return nullptr;
}