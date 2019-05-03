/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var pal_start, pal_end, curr, next;
    var slen = s.length;
    var longest_start = 0, longest_end = 0;
    var hasDiffChars = true; // false if only 1 character in palindrome
    var reset = false;

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
            }
        } else {
            // update current palidrome
            if (!hasDiffChars) {
                pal_end = curr;
                if (curr + 1 < slen) {
                    hasDiffChars = s[curr] != s[curr + 1];
                } else {
                    reset = true;
                }
            } else if (pal_start - 1 < 0) {
                // console.log("curr " + curr + " hasDiffChars " + hasDiffChars + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
                var start = pal_start + 1, end = pal_end + 1;
                var isPalindrome = true;
                // if (hasDiffChars) isPalindrome = s[curr] == s[curr - 1];
                // for (var i = 0; hasDiffChars && i < (start + end) / 2 + (start + end) % 2; i++) {
                for (var i = 0; i < Math.floor((start + end) / 2) + (start + end) % 2; i++) {
                    if (s[start + i] != s[end - i]) {
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
                    reset = true;
                }
            } else if (s[pal_start - 1] == s[pal_end + 1]) {
                pal_start--;
                pal_end++;
                if (!hasDiffChars) hasDiffChars = s[pal_start - 1] != s[pal_end + 1];
                console.log(" curr " + curr + " hasDiffChars " + hasDiffChars + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
                if (pal_end + 1 >= slen) reset = true;
                // reset = true;
            } else {
                if (s[curr - 1] == s[curr + 1]) {
                    // update palindrome indices
                    pal_start = curr - 1;
                    pal_end = curr + 1;
                    if (!hasDiffChars) hasDiffChars = s[pal_start] != s[pal_end];
                    // console.log("curr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(pal_start, pal_end + 1))
                } else {
                    reset = true;
                }
            }
        }
        
        if (reset && longest_end - longest_start <= pal_end - pal_start) {
            longest_start = pal_start;
            longest_end = pal_end;
            console.log("curr " + curr + " longest_start " + longest_start + " " + "longest_end " + longest_end + " " + " pal_start " + pal_start + " " + "pal_end " + pal_end + " ")
            // console.log("curr " + curr + " pal_start " + pal_start + " " + "pal_end " + pal_end + " " + s.substring(longest_start, longest_end + 1))

            // reset palindrome indices
            pal_start = pal_end = Math.floor((pal_start + pal_end) / 2);
            // pal_start = pal_end;
            reset = false;
            console.log("curr " + curr + " resetting to " + pal_start)
            curr = pal_start;
        }
    }
    return s.substring(longest_start, longest_end + 1);
};