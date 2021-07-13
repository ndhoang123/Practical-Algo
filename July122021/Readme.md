# Second Challenge:
[Valid Parenthenses](https://leetcode.com/problems/valid-parentheses/submissions/)

Difficulty: Easy

Status: Resolved!

#Note:
- Using [Stack](https://vnoi.info/wiki/algo/data-structures/Stack.md) to handle ordered array.
- Hint <!-- In order to handle the closest, and the far position of the character, we use stack to store the '(', '{', '[' symbol in array. For each of loop, if the current index of value is the symbol, it will push in the stack. Otherwise, if they are the opposite symbol, our function will pop the value of stack if they don't statify the condition, or return false if they statify the condition, the top of stack is not the opposite of the current symbol.-->