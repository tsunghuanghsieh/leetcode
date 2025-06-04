# [1155. Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

Given three integers `n`, `k`, and `target`, return _the number of possible ways (out of the <code>k<sup>n</sup></code> total ways) to roll the dice, so the sum of the face-up numbers equals `target`_. Since the answer may be too large, return it **modulo** <code>10<sup>9</sup> + 7</code>.

**Example 1:**
```
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
```

**Example 2:**
```
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

**Example 3:**
```
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
```

**Constraints:**
* `1 <= n, k <= 30`
* `1 <= target <= 1000`

**Bounded Integer Composition (Inclusion-Exclusion):**

$`P(n, target) = \displaystyle\sum_{\substack{i = 0}}^{\bigg\lfloor \cfrac{\scriptscriptstyle target - n}{\scriptscriptstyle k} \bigg\rfloor} (-1)^i \left( \begin{matrix} n \\ i \end{matrix} \right) \left(\begin{matrix} target - k * i - 1 \\ n - 1\end{matrix} \right)`$

where
$`\left( \begin{matrix} n \\ i \end{matrix} \right) = \cfrac {n!}{i! *(n - i)!} = \cfrac {n * (n - 1) * (n - 2) * ... * (n - i + 1)}{i * (i - 1) * (i - 2) * ... * 2 * 1 * }`$

and $`\left( \begin{matrix} n \\ i \end{matrix} \right) == \left( \begin{matrix} n \\ n - i \end{matrix} \right)`$


## Interview
As of 04/29/2025, leetcode premium subscription says Google 2 times in the last 6 months.
