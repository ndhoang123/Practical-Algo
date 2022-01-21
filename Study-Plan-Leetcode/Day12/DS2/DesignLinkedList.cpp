// https://leetcode.com/problems/design-linked-list/

#include <bits/stdc++.h>

using namespace std;

class MyLinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

private:
    Node *head;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        int count = 0;
        Node *temp = head;
        while (count != index && temp != nullptr)
        {
            // cout << temp->data << " ";
            temp = temp->next;
            ++count;
        }
        if (temp == nullptr)
        {
            return -1;
        }
        return temp->data;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        if(head == nullptr){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        Node *temp = head;
        Node *newNode = new Node();
        newNode->data = val;
        int count = 1;
        if (index == 0 || (index == 1 && head == nullptr))
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            while (count != index && temp != nullptr)
            {
                ++count;
                if(temp->next != nullptr){
                    temp = temp->next;
                }
            }
            if(index <= count && temp != nullptr){
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        Node *temp = head;
        int count = 1;
        if (index == 0)
        {
            head = head->next;
        }
        else
        {
            while (index != count && temp->next != nullptr)
            {
                temp = temp->next;
                ++count;
            }
            if (temp->next != nullptr)
            {
                temp->next = temp->next->next;
            }
        }
    }
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    // obj->addAtHead(7); // 7
    // obj->addAtHead(2); // 2-7
    // obj->addAtHead(1); // 1-2-7
    // obj->addAtIndex(3, 0); // 1-2-7-0
    // obj->deleteAtIndex(2); // 1-2-0
    // obj->addAtHead(6); // 6-1-2-0
    // obj->addAtTail(4); // 6-1-2-0-4
    obj->addAtIndex(1, 0);
    int param_1 = obj->get(4);
    cout << param_1;
    // obj->deleteAtIndex(index);
    return 0;
}