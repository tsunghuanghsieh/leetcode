package main

import (
	"fmt"
	"strings"
)

func main ()  {
	fmt.Println("length is", lengthOfLongestSubstring("pwwkew"));
}

func lengthOfLongestSubstring(input string) int {
	var longest int = 0;
	var keepLen int = 0;
	var toDelete string;
	var toKeep string;
	mapSubstr := make(map[string]string);

	for _, ch := range input {
		_, ok := mapSubstr[string(ch)];
		if (ok) {
			// fmt.Println("seeing dup ", string(ch));
			if (keepLen > longest) {
				longest = keepLen;   // update longest length
			}
			// fmt.Println("curr before ", toKeep)
			splits := strings.Split(toKeep, string(ch));
			toDelete = splits[0];
			for _, d := range toDelete {
				// see a repeated character
				// delete all characters up to and including current seen character
				delete(mapSubstr, string(d));
			}
			toKeep = splits[1];
			// fmt.Println("curr after ", toKeep)
			keepLen = len(toKeep);
		}
		// count and add the character seen
		keepLen++;
		toKeep = toKeep + string(ch);
		mapSubstr[string(ch)] = toKeep;
	}

	// in case the longest is at the end of the input string
	if (keepLen > longest) {
		longest = keepLen;
	}
	return longest;
}