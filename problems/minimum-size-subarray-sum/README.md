# [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

Given an array of positive integers `nums` and a positive integer `target`, return _the **minimal length** of a subarray, a subarray is a contiguous non-empty sequence of elements within an array, whose sum is greater than or equal to `target`_. If there is no such subarray, return `0` instead.

**Example 1:**
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

**Example 3:**
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

**Constraints:**
* <code>1 <= target <= 10<sup>9</sup></code>
* <code>1 <= nums.length <= 10<sup>5</sup></code>
* <code>1 <= nums[i] <= 10<sup>4</sup></code>

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

## Interview
As of 01/24/2025, leetcode premium subscription says Google 7 times and Amazon 3 times in the last 3 months, Microsoft 4 times in the last 6 months.
