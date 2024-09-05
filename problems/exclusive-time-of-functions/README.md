# [636. Exclusive Time of Functions](https://leetcode.com/problems/exclusive-time-of-functions/)

On a **single-threaded** CPU, we execute a program containing `n` functions. Each function has a unique ID between `0` and `n-1`.

Function calls are **stored in a** [call stack](https://en.wikipedia.org/wiki/Call_stack): when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is **the current function being executed**. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list `logs`, where `logs[i]` represents the `i^th` log message formatted as a string `"{function_id}:{"start" | "end"}:{timestamp}"`. For example, `"0:start:3"` means a function call with function ID `0` **started at the beginning** of timestamp `3`, and `"1:end:2"` means a function call with function ID `1` **ended at the end** of timestamp `2`. Note that a function can be called **multiple times, possibly recursively**.

A function's **exclusive time** is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for `2` time units and another call executing for `1` time unit, the **exclusive time** is `2 + 1 = 3`.

Return _the **exclusive time** of each function in an array, where the value at the `i^th` index represents the exclusive time for the function with ID `i`_.

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2019/04/05/diag1b.png)
```
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
```

**Example 2:**
```
Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.
```
**Example 3:**
```
Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 unit of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 6 and executes for 2 units of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.
```

**Note:**
The online judging system doesn't flag the following situations in the input at the runtime and may output incorrect ~~and negative~~ exclusive time of functions. The burden is on the test case creator to ensure the correctness of the test.
* ~~Timestamps in the log have to be in chronological order.~~ (now flagged)
* ~~Earlier function ends before later function.~~ (now flagged)
* Multiple start or end events at the same timestamp.

From the problem description, it is stated that functions are pushed onto and popped off the top of a stack as functions start and end. The function on the top of the stack is the current function being executed. A function that is not currently being executed shouldn't somehow end itself and write to the log to pop another process off the stack. It is counterintuitive; if that's the case and should be explicitly stated.

The issue with LC test case 121 has been resolved.

~~LC test case 121 ([test6.txt](https://github.com/tsunghuanghsieh/leetcode/tree/master/problems/exclusive-time-of-functions/tests/test6.txt)) does just that. In order to have the expected result, `[2,6,1]`, process `1` at the top of the stack is being executed when process `0`, while not being executed, ends and is able to writes to log to pop process `1` off the stack. And then process `0` now at the top of the stack is then being executed at `t = 7` even though it had previously ended at `t = 6`.~~

~~Bug [22693](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/22693) and [22581](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/22581) have been opened to track this.~~

**Constraints:**
* `1 <= n <= 100`
* `1 <= logs.length <= 500`
* `0 <= function_id < n`
* `0 <= timestamp <= 10^9`
* No two start events will happen at the same timestamp.
* No two end events will happen at the same timestamp.
* Each function has an `"end"` log for each `"start"` log.

## Interview
As of 06/14/2024, leetcode premium subscription says IBM 24 times and Facebook 19 times in the last 6 months.
