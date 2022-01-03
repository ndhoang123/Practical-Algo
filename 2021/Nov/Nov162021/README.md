# Bitwise operations
- [Challenge](https://www.hackerrank.com/challenges/js10-bitwise/problem?isFullScreen=true): With n, k. Writing the algo to return the maximum of bitwise operation of two numbers in n sequence(first number < two number); with the condition that the maximum in n must less than k.

- Solution:
    1. Apply math: Use formula `(k | (k - 1) > n) ? (k - 2) : (k - 1)`.