// https://leetcode.com/problems/complement-of-base-10-integer/

#include <bits/stdc++.h>

using namespace std;

int bitwiseComplement(int n){
    int temp = n, bitmask = 1;
    while(temp != 0){
        bitmask = bitmask | 1;
        temp = temp >> 1;
        if(temp != 0) bitmask = bitmask << 1;
    }
    return n ^ bitmask;
}

int main(){
    int n;
    cin >> n;
    int result = bitwiseComplement(n);
    cout << result;
    return 0;
}