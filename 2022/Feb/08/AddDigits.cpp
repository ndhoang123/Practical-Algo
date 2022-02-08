// https://leetcode.com/problems/add-digits/
// https://en.wikipedia.org/wiki/Digital_root

#include <bits/stdc++.h>

using namespace std;

int addDigits(int num){
    if(num == 0) return 0;
    if(num %9 == 0) return 9;
    return num % 9;
}

int main(){
    int n;
    cin >> n;
    int result = addDigits(n);
    cout << result;
    return 0;
}