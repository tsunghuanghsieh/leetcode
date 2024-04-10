# [62. Unique Paths](https://leetcode.com/problems/unique-paths/)

There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return _the number of possible unique paths that the robot can take to reach the bottom-right corner_.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.

Above is a 7 x 3 grid. How many possible unique paths are there?

**Note:** m and n will be at most 100.

**Example 1:**
![Robot Start to Finish](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)
```
Input: m = 7, n = 3
Output: 28
```

**Example 2:**
```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```

**Constraints**:
* `1 <= m, n <= 100`

## Interview
As of 04/09/2024, leetcode premium subscription says Amazon 6 times, Facebook 5 times and Microsoft 3 times in the last 6 months.
As of 04/09/2024, leetcode premium subscription says Google 12 times, Adobe 6 times and Apple 4 times in the last 6 - 12 months.

Someone claims [this](https://leetcode.com/discuss/interview-question/303107) is similar to his recent Facebook onsite interview question.