# [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/)

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the <code>i<sup>th</sup></code> city and the <code>j<sup>th</sup></code> city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return _the total number of **provinces_**.

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg)
```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

**Example 2:**
![Example 2](https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg)
```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
```

**Constraints:**
* `1 <= n <= 200`
* `n == isConnected.length`
* `n == isConnected[i].length`
* `isConnected[i][j]` is `1` or `0`.
* `isConnected[i][i] == 1`
* `isConnected[i][j] == isConnected[j][i]`

## Interview
04/07/2025, Amazon online assessment example CQ #2.

As of 04/07/2025, leetcode premium subscription says Amazon 6 times, Google 5 times, Uber 2 times in the last 3 months.
