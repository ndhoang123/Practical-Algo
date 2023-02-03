// https://leetcode.com/problems/happy-number/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n)
{
    unordered_map<int, int> hs;
    while (n > 1)
    {
        if(hs[n] == 0){
            hs[n]++;
        }
        else {
            return false;
        }
        int sum = 0;
        while (n)
        {
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        n = sum;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    isHappy(n) ? cout << "true" : cout << "false";
    return 0;
}