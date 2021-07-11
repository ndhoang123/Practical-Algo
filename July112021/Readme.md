# First Challenge:
[Find K Closest Element](https://leetcode.com/problems/find-k-closest-elements/)

Status: Resolved!

#Note:
- Using [Deque](https://vnoi.info/wiki/algo/data-structures/Deque.md) to handle ordered array.
- Hint <!-- I should use i, j for getting value by binary search first to get index of x value in ordered array. Then calculating the distance for each of i, j. And, push it in deque (push_front with i if distance of i less than j, push_back with j (otherwise))-->
