# Sliding window
- [Source](https://leetcode.com/tag/sliding-window/discuss/657507/Sliding-Window-for-Beginners-Problems-or-Template-or-Sample-Solutions)

- Sliding window based problems are easy to identify if we practice a few.

- Problems such as finding longest substring or shortest substring with some contraints are mostly based on sliding window.

- Basic framework of sliding window is basically 3 steps:

    **Step1**: Have a counter or hash-map to count specific array input and keep on increasing the window toward right using outer loop.

    **Step2**: Have a while loop inside to reduce the window side by sliding toward right. Movement will be based on constraints of problem. Go through few examples below

    **Step3**: Store the current maximum window size or minimum window size or number of windows based on problem requirement.