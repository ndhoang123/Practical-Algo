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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if(lists.empty()){
        return nullptr;
    }

    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }

    return lists.front();
}

int main(){
    vector<ListNode*> lists{{}};
    ListNode* n1 = new ListNode(1);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(5);
    ListNode* n2 = new ListNode(1);
    n2->next = new ListNode(3);
    n2->next->next = new ListNode(4);
    ListNode* n3 = new ListNode(2);
    n3->next = new ListNode(6);
    lists.push_back(n1);
    lists.push_back(n2);
    lists.push_back(n3);
    ListNode* result = mergeKLists(lists);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    // result == nullptr ? cout << "null" : cout << "Not null";
    return 0;
}