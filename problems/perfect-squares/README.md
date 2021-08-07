# [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)

Given a positive integer _n_, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to n.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

**Example 1:**
```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**
```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

**Constraints:**
* `1 <= n <= 104`


dp(12) = min{ dp(12 - 1 * 1) + 1, dp(12 - 2 * 2) + 1, dp(12 - 3 * 3) + 1}
       = min{ dp(11) + 1, dp(8) + 1, dp(3) + 1}

dp(11) = min{ dp(11 - 1 * 1) + 1, dp(11 - 2 * 2) + 1, dp(11 - 3 * 3) + 1}
       = min{ dp(10) + 1, dp(7) + 1, dp(2) + 1}

dp(10) = min{ dp(10 - 1 * 1) + 1, dp(10 - 2 * 2) + 1, dp(10 - 3 * 3) + 1}
       = min{ dp(9) + 1, dp(6) + 1, dp(1) + 1}

dp(9)  = min{ dp(9 - 1 * 1) + 1, dp(9 - 2 * 2) + 1, dp(9 - 3 * 3) + 1}
       = min{ dp(8) + 1, dp(5) + 1, dp(0) + 1}

dp(8)  = min{ dp(8 - 1 * 1) + 1, dp(8 - 2 * 2) + 1}
       = min{ dp(7) + 1, dp(4) + 1}

dp(7)  = min{ dp(7 - 1 * 1) + 1, dp(7 - 2 * 2) + 1}
       = min{ dp(6) + 1, dp(3) + 1}

dp(6)  = min{ dp(6 - 1 * 1) + 1, dp(6 - 2 * 2) + 1}
       = min{ dp(5) + 1, dp(2) + 1}

dp(5)  = min{ dp(5 - 1 * 1) + 1, dp(5 - 2 * 2) + 1}
       = min{ dp(4) + 1, dp(1) + 1}

dp(4)  = min{ dp(4 - 1 * 1) + 1, dp(4 - 2 * 2) + 1}
       = min{ dp(3) + 1, 1}

dp(3)  = dp(3 - 1 * 1) + 1
       = dp(2) + 1

dp(2)  = dp(2 - 1 * 1) + 1
       = dp(1) + 1

dp(1)  = 1
dp(0)  = 0

## Interview
Lyft popular interview question.