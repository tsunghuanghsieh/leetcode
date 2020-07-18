# [1. Two Sum](https://leetcode.com/problems/two-sum/)

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
```
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
```

This is a lousy problem description. It does not provide clear information on the problem.
1. size of array. (test case shows as many as 17000+ elements)
2. range of the integers in the array, if the integers is positive or negative, ~~if the integer is too big for data type number~~ (as of 07/18/2020, there is now input validation on input, 2^31 > integer >= -2^31. At one point, it was 2^53 > integer >= -2^53).
3. uniqueness of integers in the array. (test cases show they are not)

Note:
Given there is exactly one solution, the two integers in the solution will be either unique or of the same value. In the example given above, there is going to be one instance each of 2 and 7. Given nums = [3, 3, 5, 7, 7, 7], target = 6. Since there is exactly one solution, there will only be at most 2 instances of 3.