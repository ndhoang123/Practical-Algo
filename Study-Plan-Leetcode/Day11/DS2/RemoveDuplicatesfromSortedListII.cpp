// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* sentisel = new ListNode(0, head);
    ListNode* pred = sentisel;
    while(head != nullptr){
        if(head->next != nullptr && head->next->val == head->val){
            while (head->next != nullptr && head->next->val == head->val)
            {
                head = head->next;
            }
            pred->next = head->next;
        }
        else{
            pred = pred->next;
        }
        head = head->next;
    }
    return sentisel->next;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    ListNode* result = deleteDuplicates(head);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}