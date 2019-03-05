3. [Longest Substring Without Repeating](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string, find the length of the longest substring without repeating characters.

Example 1:
```
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

Example 2:
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

Example 3:
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

# Setup
* Install Go from https://golang.org/
* Install Go extension for Visual Studio Code.
* Install `go get -v github.com/go-delve/delve/cmd/dlv` to `$GOPATH`. If there are several paths, the first one will be used.
* Executable `dlv` will be in `$GOPATH/bin` folder. You can move it to `/usr/local/bin` so that you don't have to update `$PATH`.
