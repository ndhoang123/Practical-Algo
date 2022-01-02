// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

bool hasCycle(ListNode *head)
{
    if(!head) return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    
}