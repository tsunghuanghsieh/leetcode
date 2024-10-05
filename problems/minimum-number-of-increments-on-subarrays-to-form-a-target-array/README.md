# [1526. Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)

You are given an integer array `target`. You have an integer array `initial` of the same size as `target` with all elements initially zeros.

In one operation you can choose **any** subarray from `initial` and increment each value by one.

Return _the minimum number of operations to form a `target` array from `initial`_.

The test cases are generated so that the answer fits in a 32-bit integer.

**Example 1:**
<pre>
<b>Input:</b>  target = [1,2,3,2,1]
<b>Output:</b> 7
<b>Explanation:</b> We need at least 3 operations to form the target array from the initial array.
[<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>] increment 1 from index 0 to 4 (inclusive).
[1,<ins><b>1</b></ins>,<ins><b>1</b></ins>,<ins><b>1</b></ins>,1] increment 1 from index 1 to 3 (inclusive).
[1,2,<ins><b>2</b></ins>,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
</pre>

**Example 2:**
<pre>
<b>Input:</b> target = [3,1,1,2]
<b>Output:</b> 4
<b>Explanation:</b> [<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>] -> [1,1,1,<ins><b>1</b></ins>] -> [<ins><b>1</b></ins>,1,1,2] -> [<ins><b>2</b></ins>,1,1,2] -> [3,1,1,2]
</pre>

**Example 3:**
<pre>
<b>Input:</b>  target = [3,1,5,4,2]
<b>Output:</b> 7
<b>Explanation:</b> [<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>,<ins><b>0</b></ins>] -> [<ins><b>1</b></ins>,1,1,1,1] -> [<ins><b>2</b></ins>,1,1,1,1] -> [3,1,<ins><b>1</b></ins>,<ins><b>1</b></ins>,<ins><b>1</b></ins>] -> [3,1,<ins><b>2</b></ins>,<ins><b>2</b></ins>,2] -> [3,1,<ins><b>3</b></ins>,<ins><b>3</b></ins>,2] -> [3,1,<ins><b>4</b></ins>,4,2] <br> -> [3,1,5,4,2].
</pre>

**Constraints:**
* <code>1 <= target.length <= 10<sup>5</sup></code>
* <code>1 <= target[i] <= 10<sup>5</sup></code>

## Interview
As of 10/03/2024, leetcode premium subscription says Google 56 times, Amazon 2 times in the last 3 months.
