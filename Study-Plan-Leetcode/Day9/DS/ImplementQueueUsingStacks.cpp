// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
        return value;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && !s2.empty()){
            return s2.empty();
        }
        return s1.empty();
    }
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int value = obj->pop();
    cout << "Value 1:" << value << endl;
    obj->push(5);
    value = obj->pop();
    cout << "Value 2:" << value << endl;
    value = obj->pop();
    cout << "Value 2:" << value << endl;
    value = obj->pop();
    cout << "Value 2:" << value << endl;
    value = obj->pop();
    cout << "Value 2:" << value << endl;
    obj->empty() ? cout << "true" : cout << "false";
    return 0;
}