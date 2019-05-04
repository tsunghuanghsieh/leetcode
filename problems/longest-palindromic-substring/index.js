var pal_start, pal_end, curr, next;
var slen;
var longest_start = 0, longest_end = 0;
var hasDiffChars = true; // false if only 1 character in palindrome
var reset = false;
var loopIdx = 0;

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    hasDiffChars = true; // false if only 1 character in palindrome
    longest_start = 0;
    longest_end = 0;
    loopIdx = 0;
    reset = false;
    slen = s.length;

    // special cases
    if (slen == 1) return s;

    for (curr = 0, next = 1, pal_start = 0, pal_end = 0; curr < slen; curr++, next++) {
        if (pal_start == pal_end) {
            // console.log("curr " + curr + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
            // start a new palindrome
            if (s[curr] == s[curr + 1]) {
                pal_start = curr;
                pal_end = curr + 1;
                hasDiffChars = s[curr] != s[curr + 1];
                // console.log("curr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(pal_start, pal_end + 1))
            } else if (curr != 0 && s[curr - 1] == s[curr + 1]) {
                pal_start = curr - 1;
                pal_end = curr + 1;
                hasDiffChars = s[curr] != s[curr + 1];
                // console.log("acurr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(pal_start, pal_end + 1))
            } else if (curr + 1 == slen) {
                pal_start = curr;
                pal_end = curr;
                updateLongest();
            }
        } else {
            // update current palidrome
            if (!hasDiffChars) {
                pal_end = curr;
                if (curr + 1 < slen) {
                    hasDiffChars = s[curr] != s[curr + 1];
                    // we can't confirm if it's not a palindrome until the next char, don't reset just yet
                } else {
                    // reach end of the string, update longest palindrome
                    // updateLongest(longest_start, longest_end, pal_start, pal_end);
                    updateLongest();
                }
            } else if (pal_start - 1 < 0) {
                // console.log("curr " + curr + " hasDiffChars " + hasDiffChars + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
                var start = pal_start + 1, end = pal_end + 1;
                var isPalindrome = true;
                // if (hasDiffChars) isPalindrome = s[curr] == s[curr - 1];
                // for (loopIdx = 0; hasDiffChars && loopIdx < (start + end) / 2 + (start + end) % 2; loopIdx++) {
                for (loopIdx = 0; loopIdx < Math.floor((start + end) / 2) + (start + end) % 2; loopIdx++) {
                    if (s[start + loopIdx] != s[end - loopIdx]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome) {
                    // shift palindrome by 1 character
                    // if (hasDiffChars) pal_start++;
                    pal_start++;
                    pal_end++;
                    // console.log("curr " + curr + " shifting")
                } else {
                    console.log("resetPalindromeIndices")
                    resetPalindromeIndices(s);
                }
            } else if (s[pal_start - 1] == s[pal_end + 1]) {
                pal_start--;
                pal_end++;
                if (!hasDiffChars) hasDiffChars = s[pal_start - 1] != s[pal_end + 1];
                console.log(" curr " + curr + " hasDiffChars " + hasDiffChars + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
                if (pal_end + 1 >= slen) reset = true;
                // reset = true;
            } else {
                resetPalindromeIndices(s);
            }
        }
        
        /*
        if (reset && longest_end - longest_start <= pal_end - pal_start) {
            longest_start = pal_start;
            longest_end = pal_end;
            console.log("curr " + curr + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
            // console.log("curr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(longest_start, longest_end + 1))

            // reset palindrome indices
            // pal_start = pal_end = Math.floor((pal_start + pal_end) / 2);
            pal_start = pal_end = curr;
            reset = false;
            console.log("curr " + curr + " resetting to " + pal_start)
            // curr = pal_start;
        }
        */
        if (reset) {
            updateLongest();
            pal_start = pal_end = curr;
            reset = false;
        }
    }
    return s.substring(longest_start, longest_end + 1);
};

function resetPalindromeIndices(s) {
    // check if curr and curr + 1 is the same char
    console.log("curr " + curr)
    if (s[curr] == s[curr + 1]) {
        // aaabbbcbbbb...
        // look back on bbbb after c
        for (loopIdx = 1; s[curr - loopIdx] == s[curr]; loopIdx++) { /* do nothing loop */ }
        // update longest palindrome
        updateLongest();

        pal_start = curr - loopIdx + 1;
        pal_end = curr + 1;
        hasDiffChars = !(pal_end - pal_start > 0);
    } else if (s[curr - 1] == s[curr + 1]) {
        // aaaxyzczyxy...
        // update longest palindrome
        updateLongest();
                    
        // update palindrome indices
        pal_start = curr - 1;
        pal_end = curr + 1;
        if (!hasDiffChars) hasDiffChars = s[curr] != s[curr + 1];
        // console.log("curr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(pal_start, pal_end + 1))
    } else {
        reset = true;
    }
}
function updateLongest() {
    console.log("updateLongest " + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
    if (longest_end - longest_start <= pal_end - pal_start) {
        longest_start = pal_start;
        longest_end = pal_end;
    }
    console.log("updateLongest " + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
}
