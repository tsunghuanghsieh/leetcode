# [1930. Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

Given a string `s`, return _the number of **unique palindromes of length three** that are a **subsequence** of `s`_.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted **once**.

A **palindrome** is a string that reads the same forwards and backwards.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of <code>"abcde"</code>.

**Example 1:**
<pre>
<b>Input:</b> s = "aabca"
<b>Output:</b> 3
<b>Explanation:</b> The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "<ins>a</ins>a<ins>b</ins>c<ins>a</ins>")
- "aaa" (subsequence of "<ins>a</ins><ins>a</ins>bc<ins>a</ins>")
- "aca" (subsequence of "<ins>a</ins>ab<ins>c</ins><ins>a</ins>")
</pre>

**Example 2:**
<pre>
<b>Input:</b> s = "adc"
<b>Output:</b> 0
<b>Explanation:</b> There are no palindromic subsequences of length 3 in "adc".
</pre>

**Example 3:**
<pre>
<b>Input:</b> s = "bbcbaba"
<b>Output:</b> 4
<b>Explanation:</b> The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "<ins>b</ins><ins>b</ins>c<ins>b</ins>aba")
- "bcb" (subsequence of "<ins>b</ins>b<ins>c</ins><ins>b</ins>aba")
- "bab" (subsequence of "<ins>b</ins>bcb<ins>a</ins><ins>b</ins>a")
- "aba" (subsequence of "bbcb<ins>a</ins><ins>b</ins><ins>a</ins>")
</pre>

**Constraints:**
* <code>3 <= s.length <= 10<sup>5</sup></code>
* `s` consists of only lowercase English letters.

## Interview
As of 01/05/2025, leetcode premium subscription says Google 11 times, Amazon 7 times and Facebook 5 times in the last 3 months.
