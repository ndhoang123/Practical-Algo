// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
    vector<int> v;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        if(v.empty()) return;
        v.pop_back();
    }

    int top()
    {
        int n = v.size();
        return v[n - 1];
    }

    int getMin()
    {
        int min = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < min)
            {
                min = v[i];
            }
        }
        return min;
    }
};

int main()
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int val = minStack->getMin(); // return -3
    cout << val << endl;
    minStack->pop();
    int val1 = minStack->top();    // return 0
    cout << val1 << endl;
    int val2 = minStack->getMin(); // return -2
    cout << val2 << endl;
    return 0;
}