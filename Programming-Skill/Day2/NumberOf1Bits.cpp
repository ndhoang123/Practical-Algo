// https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int hammingWeight(uint32_t n)
{
    return bitset<32>(n).count();
}

int main()
{
    int res;
    uint32_t v = 00000000000000000000000000001011;
    res = hammingWeight(v);
    cout << res;
    return 0;
}