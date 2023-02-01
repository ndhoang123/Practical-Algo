// https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan&id=programming-skills-i
#include <iostream>
#include <vector>

using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0){
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int main()
{
    int res;
    uint32_t v = 00000000000000000000000000001011;
    res = hammingWeight(v);
    cout << res;
    return 0;
}