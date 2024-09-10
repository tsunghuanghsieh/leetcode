# [959. Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/)

An `n x n` grid is composed of `1 x 1` squares where each `1 x 1` square consists of a `'/'`, `'\'`, or blank space `' '`. These characters divide the square into contiguous regions.

Given the grid `grid` represented as a string array, return _the number of regions_.

Note that backslash characters are escaped, so a `'\'` is represented as `'\\'`.

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2018/12/15/1.png)
```
Input: grid = [" /","/ "]
Output: 2
```

**Example 2:**

![Example 2](https://assets.leetcode.com/uploads/2018/12/15/2.png)
```
Input: grid = [" /","  "]
Output: 1
```

**Example 3:**

![Example 3](https://assets.leetcode.com/uploads/2018/12/15/3.png)
```
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
```

**Constraints:**
* `n == grid.length == grid[i].length`
* `1 <= n <= 30`
* `grid[i][j]` is either `'/'`, `'\'`, or `' '`.

## Interview
As of 09/09/2024, leetcode premium subscription says Google 18 times, Facebook and Amazon 3 times in the last 3 months.
