# [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**
```
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**
* <code>1 <= s.length, t.length <= 5 * 10<sup>4</sup></code>
* `s` and `t` consist of lowercase English letters.

Empirical data confirms if `s.length` and `t.length` are not the same, `t` is not an anagram of `s`. From the explanation of **Anagram** above, I thought `t` would still be an anagram of `s` if `t` has extra letters in addition to all the original letters in `s`.

## Interview
As of 09/11/2023, leetcode premium subscription says Amazon 7 times, Microsoft 4 times, Apple 3 times, Google, Adobe 2 times in the last 6 months.
