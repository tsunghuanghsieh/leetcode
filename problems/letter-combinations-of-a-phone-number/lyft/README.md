# Lyft variant

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![Telephone Keypad](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Given an input file that contains a list of dictionary words followed by a list of sequence of digits. For each sequence of digits, return all possible words in the dictionary that could match the sequences of digits.

The input file will contain words in CAPS separated by newline character, followed by a sequence of digits seperated by newline character. Dictionary ends when sequence of digits starts.

Your output should contain one line for each of sequence of digits in the input file. The outputed words should be in lowercase. Each line will be formatted as follows.
`<sequence of digits>: <comma separated list of words> or '<No Results>'`

**Sample Output**
```
222: aaa, abc
63: me, of
23456789: <No Results>
```

**Example:**
```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

**Note:**
Although the above answer is in lexicographical order, your answer could be in any order you want.