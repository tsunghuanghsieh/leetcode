# [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the **minimum window** substring (A substring is a contiguous non-empty sequence of characters within a string) of `s` such that every character in `t` (**including duplicates**) is included in the window_. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is **unique**.

**Example 1:**
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**
```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

**Example 3:**
```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

**Constraints:**
* `m == s.length`
* `n == t.length`
* <code>1 <= m, n <= 10<sup>5</sup></code>
* `s` and `t` consist of uppercase and lowercase English letters.

**Note:** it's case sensitive.

**Follow up**: Could you find an algorithm that runs in `O(m + n)` time?

## Interview
As of 08/09/2024, leetcode premium subscription says Facebook 5 times, Uber 3 times, Google, Amazon, LinkedIn, AirBnb, Lyft 2 times in the last 3 months.
