// https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    void reverse(){
        Node* current = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
 
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();

    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}

/*
ListNode *reverseList(ListNode* head){
    stack<int> st;
    ListNode* temp = head;
    while(temp->next != NULL){
        st.push(temp->val);
        temp = temp->next;
    }
    while(head->next != NULL){
        head->val = st.top();
        st.pop();
        head = temp->next;
    }
    return head;
}
*/