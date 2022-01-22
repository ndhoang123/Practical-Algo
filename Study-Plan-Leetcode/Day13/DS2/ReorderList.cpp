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

void reorderList(ListNode *head)
{
    deque<ListNode*> de;
    ListNode* temp = head->next;
    while(temp != nullptr){
        de.push_back(temp);
        temp = temp->next;
    }
    ListNode* itr = head;
    while(!de.empty()){
        ListNode* back = de.back();
        de.pop_back();
        itr->next = back;
        itr = itr->next;
        if(de.empty()){
            itr->next = nullptr;
            itr = itr->next;
            break;
        }
        ListNode* front = de.front();
        de.pop_front();
        itr->next = front;
        itr = itr->next;
        if(de.empty()){
            itr->next = nullptr;
            itr = itr->next;
            break;
        }
    }
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reorderList(head);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}