// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>

using namespace std;

struct NodeList{
    int val;
    NodeList* next;
    NodeList(int val) : val(val), next(nullptr) {}
};

int removeDuplicates(vector<int> &nums)
{
    int count = 0;
    int i = 0;
    int lastElem = nums[0];
    NodeList* head = new NodeList(0);
    NodeList* temp = head;
    for(auto it : nums){
        if(it == lastElem){
            ++count;
            if(count < 3){
                temp->next = new NodeList(it);
                temp = temp->next;
            }
        }
        else{
            count = 1;
            temp->next = new NodeList(it);
            lastElem = it;
            temp = temp->next;
        }
    }
    temp->next = nullptr;
    head = head->next;
    count = 0;
    while(head != nullptr){
        cout << head->val << " ";
        ++count;
        nums[i] = head->val;
        head = head->next;
        ++i;
    }
    return count;
}

int main(){
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int result = removeDuplicates(nums);
    cout << result;
    return 0;
}