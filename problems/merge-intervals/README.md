# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**
```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```
**Example 2:**
```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```
**NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


Problem description is lousy and inadequate. The examples given seem to imply input is sorted, but it is not.

## Runtime
O(n log m) where `n` is the number of intervals in the input and `m` is the number of disjoint intervals (`m` <= `n`).

## Interview
As of 07/01/2019, leetcode premium subscription says Facebook 27 times, Google 21 times, Amazon 21 times in the last 6 months.
