# [1984. Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the <code>i<sup>th</sup></code> student. You are also given an integer`k`.

Pick the scores of any `k` students from the array so that the **difference** between the **highest** and the **lowest** of the `k` scores is **minimized**.

Return _the **minimum** possible difference_.

**Example 1:**
<code>
<b>Input:</b> nums = [90], k = 1
<b>Output:</b> 0
<b>Explanation:</b> There is one way to pick score(s) of one student:
- [<ins><b>90</b></ins>]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.
</code>

**Example 2:**
<code>
<b>Input:</b> nums = [9,4,1,7], k = 2
<b>Output:</b> 2
<b>Explanation:</b> There are six ways to pick score(s) of two students:
- [<ins><b>9</ins></b>,<ins><b>4</ins></b>,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [<ins><b>9</ins></b>,4,<ins><b>1</ins></b>,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [<ins><b>9</ins></b>,4,1,<ins><b>7</ins></b>]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,<ins><b>4</ins></b>,<ins><b>1</ins></b>,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,<ins><b>4</ins></b>,1,<ins><b>7</ins></b>]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,<ins><b>1</ins></b>,<ins><b>7</ins></b>]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
</code>

**Constraints:**
*  `1 <= k <= nums.length <= 1000`
* <code>0 <= nums[i] <= 10<sup>5</sup></code>

## Interview
As of 04/30/2025, leetcode premium subscription says Amazon 2 times in the last 3 months; Google 4 times, Facebook 3 times in  the last 6 months.
