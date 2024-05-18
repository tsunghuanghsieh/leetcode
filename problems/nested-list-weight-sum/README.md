# [339. Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/) (**Premium**)

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists.

The **depth** of an integer is the number of lists that it is inside of. For example, the nested list `[1,[2,2],[[3],2],1]` has each integer's value set to its **depth**.

Return _the sum of each integer in `nestedList` multiplied by its **depth**_.

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex1.png)
```
Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
```

**Example 2:**
![Example 2](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex2.png)
```
Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.
```

**Example 3:**
```
Input: nestedList = [0]
Output: 0
```

**Constraints:**
* `1 <= nestedList.length <= 50`
* The values of the integers in the nested list is in the range `[-100, 100]`.
* The maximum **depth** of any integer is less than or equal to `50`.

## Interview
As of 05/10/2024, leetcode premium subscription says Facebook 123 times, Linkedin 3 times and Google 2 times in the last 6 months.