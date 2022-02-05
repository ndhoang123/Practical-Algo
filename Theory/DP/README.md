# Dynamic Programming (DP)
- [What is DP](#What-is-the-dp): The definition of DP.
- [Bottom-up and Top-down](#Two-way-implementation-of-DP): Two ways to implement DP.
- [When to use DP](#When-to-use-DP): How to identify which the problem uses DP or not.

## What is the DP?

- **Dynamic Programming (DP)** is a programming paradigm that can systematically and efficiently explore all possible solutions to a problem. As such, it is capable of solving a wide variety of problems that often have the following characteristics:
    
    1. The problem can be broken down into "**overlapping subproblems**" - smaller versions of the original problem that are re-used multiple times.

    2. The problem has an "**optimal substructure**" - an optimal solution can be formed from optimal solutions to the overlapping subproblems of the original problem.

- **Dynamic programming** is **a powerful tool** because it can `break a complex problem into manageable subproblems`, `avoid unnecessary recalculation of overlapping subproblems`, and `use the results of those subproblems to solve the initial complex problem`. **DP not only aids us in solving complex problems**, but it also **greatly improves the time complexity compared to brute force solutions**.

## Two-way implementation of DP:

1. **Bottom-up (tabulation):**
- Bottom-up is implemented with iteration and starts at the base cases. 

2. **Top-down (Memoization):**
- Top-down is implemented with recursion and made efficient with memoization.

    `memoizing a result means to store the result of a function call, usually in a hashmap or an array, so that when the same function call is made again, we can simply return the memoized result instead of recalculating the result.`

3. **Which is better?**
- Any DP algorithm can be implemented with either method, and there are reasons for choosing either over the other. However, each method has one main advantage that stands out:
    + A **bottom-up implementation's runtime** is usually **faster**, as iteration does not have the overhead that recursion does.

    + A **top-down implementation** is usually much **easier to write**. This is `because with recursion`, `the ordering of subproblems does not matter`, whereas with `tabulation`, we need to `go through a logical ordering of solving subproblems`.

## When to use DP
- In the first section, we defined what makes a problem a good candidate for dynamic programming. Recall:

    + The problem can be broken down into "**overlapping subproblems**" - smaller versions of the original problem that are re-used multiple times.

    + The problem has an "**optimal substructure**" - an optimal solution can be formed from optimal solutions to the overlapping subproblems of the original problem.

- Unfortunately, it is hard to identify when a problem fits into these definitions. Instead, let's discuss some common characteristics of DP problems that are easy to identify.

- **The first characteristic** that is common in DP problems is that the problem will ask for the optimum value (maximum or minimum) of something, or the number of ways there are to do something. For example:

    + What is the minimum cost of doing...
    + What is the maximum profit from...
    + How many ways are there to do...
    + What is the longest possible...
    + Is it possible to reach a certain point...

    `Note: Not all DP problems follow this format, and not all problems that follow these formats should be solved using DP. However, these formats are very common for DP problems and are generally a hint that you should consider using dynamic programming.`

    Sometimes, a problem in this format (asking for the max/min/longest etc.) is meant to be solved with a greedy algorithm. The next characteristic will help us determine whether a problem should be solved using a greedy algorithm or dynamic programming.

- **The second characteristic** that is common in DP problems is that future "decisions" depend on earlier decisions. Deciding to do something at one step may affect the ability to do something in a later step.

    `When you're solving a problem on your own and trying to decide if the second characteristic is applicable, assume it isn't, then try to think of a counterexample that proves a greedy algorithm won't work. If you can think of an example where earlier decisions affect future decisions, then DP is applicable.`

    To summarize: if a problem is **asking for the maximum/minimum/longest/shortest of something**, **the number of ways to do something**, or if it is **possible to reach a certain point**, it is probably `greedy or DP`. Although, in general, if the problem has **constraints that cause decisions to affect other decisions**, such as using one element prevents the usage of other elements, then we should **consider using dynamic programming to solve the problem**.