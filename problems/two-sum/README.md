# [1. Two Sum](https://leetcode.com/problems/two-sum/)

Given an array of integers `nums` and integer `target`, return _indices of the two numbers such that they add up to a specific `target`_.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**
```
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**
```
    Input: nums = [3,2,4], target = 6
    Output: [1,2]
```

**Example 3:**
```
    Input: nums = [3,3], target = 6
    Output: [0,1]
```

~~This is a lousy problem description. It does not provide clear information on the problem.~~
1. ~~size of array. (test case shows as many as 17000+ elements)~~
2. ~~range of the integers in the array, if the integers is positive or negative, if the integer is too big for data type number (as of 07/18/2020, there is now input validation on input, 2^31 > integer >= -2^31. At one point, it was 2^53 > integer >= -2^53)~~
3. ~~uniqueness of integers in the array. (test cases show they are not)~~

As of 08/29/2023, there are 3 constraints and additional examples to clarify the problem.

**Constraints:**
* 2 <= nums.length <= 10<sup>4</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
* -10<sup>9</sup> <= target <= 10<sup>9</sup>


Note:
Given there is exactly one solution, the two integers in the solution will be either unique or of the same value. In the example given above, there is going to be one instance each of 2 and 7. Given nums = [3, 3, 5, 7, 7, 7], target = 6. Since there is exactly one solution, there will only be at most 2 instances of 3.