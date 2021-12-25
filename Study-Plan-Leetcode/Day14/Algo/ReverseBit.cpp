// https://leetcode.com/problems/reverse-bits/
#include<bits/stdc++.h>

using namespace std;

uint32_t reverseBit(uint32_t n){
    uint32_t result = 0;
    for(int i = 0; i < 32; i++){
        result = result << 1;
        if(n & 1 == 1){
            result = result | 1;
        }
        else if(n & 1 == 0){
            result = result | 0;
        }
        n = n >> 1;
    }
    return result;
}

int main(){
    uint32_t result;
    uint32_t n;
    cin >> n;
    result = reverseBit(n);
    cout << result;
    return 0;
}