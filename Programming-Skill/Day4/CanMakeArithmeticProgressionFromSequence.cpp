// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    if (arr.size() == 2)
    {
        return true;
    }
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] - arr[i] != diff)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 0, 1};
    canMakeArithmeticProgression(arr) ? cout << "true" : cout << "false";
    return 0;
}