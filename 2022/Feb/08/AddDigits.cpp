// https://leetcode.com/problems/add-digits/

#include <bits/stdc++.h>

using namespace std;

int addDigits(int num){
    int result = 0;
    while(num > 0){
        result += num%10;
        num = num/10;
        if(num == 0 && result > 9){
            num = result;
            result = 0;
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    int result = addDigits(n);
    cout << result;
    return 0;
}