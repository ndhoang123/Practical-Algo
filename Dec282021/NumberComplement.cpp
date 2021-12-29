// https://leetcode.com/problems/number-complement/

#include <bits/stdc++.h>

using namespace std;

int findComplement(int num){
    int mask = 0;
    for(int tmp = num; tmp; tmp >>= 1){
        mask = (mask << 1) | 1;
    }
    return mask ^ num;
}

int main(){
    int num;
    cin >> num;
    int result = findComplement(num);
    cout << result;
    return 0;
}