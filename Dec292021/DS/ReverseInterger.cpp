// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    if (x > INT_MAX || x < INT_MIN)
        return 0;
    bool isNegative = false;
    int result = 0, temp = 0;
    if(x < 0) isNegative = true;
    x = abs(x);
    while(x != 0){
        result = result*10 + x%10;
        x = x / 10;
    }
    if(isNegative) return -result;
    return result;
}

int main(){
    int x;
    cin >> x;
    int result = reverse(x);
    cout << result << " ";
    cout << INT_MAX;
    return 0;
}