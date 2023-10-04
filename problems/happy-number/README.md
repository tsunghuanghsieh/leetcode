# [202. Happy Number](https://leetcode.com/problems/happy-number/)

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

* Starting with any positive integer, replace the number by the sum of the squares of its digits.
* Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
* Those numbers for which this process **ends in 1** are happy.

Return `true` if `n` is a happy number, and `false` if not.

**Example 1:**
```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**Example 2:**
```
Input: n = 2
Output: false
```

**Constraints:**
* 1 <= n <= 2<sup>31</sup> - 1

## Interview
As of 09/11/2023, leetcode premium subscription says Accenture 8 times, Apple 5 times, Amazon 4 times, Adobe and Cisco 3 times in the last 6 months.

## Solution
Time complexity is `O(log n)`.
Space complexity for hash table is `O(log n)`.
Space complexity for Floyd Cycle detection using 2 runners (fast and slow) is `O(1)`.
Space complexity for hardcoding all numbers in the one and only cycle, `{4, 16, 37, 58, 89, 145, 42, 20}`, is `O(1)`.
