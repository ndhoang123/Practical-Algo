// https://leetcode.com/problems/complement-of-base-10-integer/

#include <bits/stdc++.h>

using namespace std;

int bitwiseComplement(int n){
    int bitmask = 1;
    while(bitmask < n){
        bitmask = (bitmask << 1) + 1;
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