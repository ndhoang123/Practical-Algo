// https://leetcode.com/problems/merge-k-sorted-lists/

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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if(lists.empty()) return nullptr;
    priority_queue<pair<int, ListNode*>> he;
    for(int i = 0; i < lists.size(); i++){
        ListNode* temp = lists[i];
        while(temp != nullptr){
            he.push({temp->val, temp});
            temp = temp->next;
        }
    }
    ListNode* result = nullptr;
    while(!he.empty()){
        ListNode* temp = he.top().second;
        he.pop();
        temp->next = result;
        result = temp;
    }
    return result;
}

int main(){
    vector<ListNode*> lists{{}};
    // ListNode* n1 = new ListNode(1);
    // n1->next = new ListNode(4);
    // n1->next->next = new ListNode(5);
    // ListNode* n2 = new ListNode(1);
    // n2->next = new ListNode(3);
    // n2->next->next = new ListNode(4);
    // ListNode* n3 = new ListNode(2);
    // n3->next = new ListNode(6);
    // lists.push_back(n1);
    // lists.push_back(n2);
    // lists.push_back(n3);
    ListNode* result = mergeKLists(lists);
    // while(result != nullptr){
    //     cout << result->val << " ";
    //     result = result->next;
    // }
    result == nullptr ? cout << "null" : cout << "Not null";
    return 0;
}