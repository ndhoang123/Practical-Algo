// https://leetcode.com/problems/n-th-tribonacci-number/

#include <bits/stdc++.h>

using namespace std;

int tribonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    int lastThree = 0, lastTwo = 1, lastOne = 1;
    int sum = 0;
    for(int i = 3; i <= n; i++){
        sum = lastThree + lastTwo + lastOne;
        lastThree = lastTwo;
        lastTwo = lastOne; 
        lastOne = sum;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int result = tribonacci(n);
    cout << result;
    return 0;
}