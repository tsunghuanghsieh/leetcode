# [1526. Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)

You are given an integer array `target`. You have an integer array `initial` of the same size as `target` with all elements initially zeros.

In one operation you can choose **any** subarray from `initial` and increment each value by one.

Return _the minimum number of operations to form a `target` array from `initial`_.

The test cases are generated so that the answer fits in a 32-bit integer.

**Example 1:**
> **Input:** target = [1,2,3,2,1]
> **Output:** 3
> **Explanation:** We need at least 3 operations to form the target array from the initial array.
> [<u>0</u>,<u>0</u>,<u>0</u>,<u>0</u>,<u>0</u>] increment 1 from index 0 to 4 (inclusive).
> [1,<u>1</u>,<u>1</u>,<u>1</u>,1] increment 1 from index 1 to 3 (inclusive).
> [1,2,<u>2</u>,2,1] increment 1 at index 2.
> [1,2,3,2,1] target array is formed.

**Example 2:**
> **Input:** target = [3,1,1,2]
> **Output:** 4
> **Explanation:** [<u>0</u>,<u>0</u>,<u>0</u>,<u>0</u>] -> [1,1,1,<u>1</u>] -> [<u>1</u>,1,1,2] -> [<u>2</u>,1,1,2] -> [3,1,1,2]

**Example 3:**
> **Input:** target = [3,1,5,4,2]
> **Output:** 7
> **Explanation:** [<u>0</u>,<u>0</u>,<u>0</u>,<u>0</u>,<u>0</u>] -> [<u>1</u>,1,1,1,1] -> [<u>2</u>,1,1,1,1] -> [3,1,<u>1</u>,<u>1</u>,<u>1</u>] -> [3,1,<u>2</u>,<u>2</u>,2] -> [3,1,<u>3</u>,<u>3</u>,2] -> [3,1,<u>4</u>,4,2] -> [3,1,5,4,2].

**Constraints:**
* <code>1 <= target.length <= 10<sup>5</sup></code>
* <code>1 <= target[i] <= 10<sup>5</sup></code>

## Interview
As of 10/03/2024, leetcode premium subscription says Google 56 times, Amazon 2 times in the last 3 months.
