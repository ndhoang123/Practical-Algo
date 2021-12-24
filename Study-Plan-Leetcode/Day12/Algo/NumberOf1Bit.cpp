// https://leetcode.com/problems/number-of-1-bits/
#include<bits/stdc++.h>

using namespace std;

int hammingWeight(uint32_t n){
    int count = 0;
    for(int i = 0; i < 32; i++){
        if((n & 1) == 1){
            cout << n << " ";
            ++count;
        }
        n = n >> 1;
    }
    return count;
}

int main(){
    uint32_t n;
    cin >> n;
    int result = hammingWeight(n);
    cout << result;
    return 0;
}