# [6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:
```
string convert(string s, int numRows);
```

Example 1:
```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

Example 2:
```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

## Explanation
Distance between characters on the same row is shown below.
```
3 Rows
P    <4>    A    <4>    H    <4>    N
A <2> P <2> L <2> S <2> I <2> I <2> G
Y    <4>    I    <4>    R
```
```
4 Rows
P    <6>    I    <6>    N
A <4> L <2> S <4> I <2> G
Y <2> A <4> H <2> R
P    <6>    I
```
```
5 Rows
P      <8>      H
A <6>     S <2> I
Y <4>   I   <4> R
P <2> L     <6> I <2> G
A      <8>      N
```
A pattern has emerged, and I am able to construct a (rows by 2) distance array to look up characters on each row.
Edge rows are special cases.

## Build/Run
From Mac/*nix terminal with g++ compiler installed, run the following to generate and run executable.
```
make
./a.out
```