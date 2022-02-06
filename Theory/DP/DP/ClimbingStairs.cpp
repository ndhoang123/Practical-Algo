// https://leetcode.com/problems/climbing-stairs/
// 06-Feb-2022

#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    int lastestStair = 2, lastStair = 1, currentStair;
    for(int i = 3; i <= n; i++){
        currentStair = lastestStair + lastStair;
        lastStair = lastestStair;
        lastestStair = currentStair;
    }
    return currentStair;
}

int main(){
    int n;
    cin >> n;
    int result = climbStairs(n);
    cout << result;
    return 0;
}