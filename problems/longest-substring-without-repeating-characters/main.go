package main

import (
	"fmt"
	// "strings"
)

func main ()  {
	fmt.Println("length is", lengthOfLongestSubstring("abcabcbb"));
	// fmt.Println("length is", lengthOfLongestSubstring("bbbbb"));
	// fmt.Println("length is", lengthOfLongestSubstring("pwwkew"));
	// fmt.Println("length is", lengthOfLongestSubstring("dvdf"));
	// fmt.Println("length is", lengthOfLongestSubstring("abba"));
	// fmt.Println("length is", lengthOfLongestSubstring("abcdefgchijkbcbb"));
}

func lengthOfLongestSubstring(input string) int {
	var longest int = 0;
	var startIdx int = 0;
	// string in map seems to run faster than byte, however memory usage is worse
	mapSubstr := make(map[string]int); // latest position (array index + 1) of character in string

	for pos := 0; pos < len(input); pos++ {
        if (mapSubstr[string(input[pos])] != 0 && mapSubstr[string(input[pos])] > startIdx) {
			// we have seen this character the current substring
			startIdx = mapSubstr[string(input[pos])];
			// fmt.Println("startIdx ", startIdx);
		}
		mapSubstr[string(input[pos])] = pos + 1;

		if (longest < pos + 1 - startIdx) {
			longest = pos + 1 - startIdx;
		}
	}
	return longest;
}