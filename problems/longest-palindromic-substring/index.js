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
            // start a new palindrome
            if (s[curr] == s[curr + 1]) {
                pal_start = curr;
                pal_end = curr + 1;
                hasDiffChars = s[curr] != s[curr + 1];
            } else if (curr != 0 && s[curr - 1] == s[curr + 1]) {
                pal_start = curr - 1;
                pal_end = curr + 1;
                hasDiffChars = s[curr] != s[curr + 1];
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
                    updateLongest();
                }
            } else if (pal_start - 1 < 0) {
                var start = pal_start + 1, end = pal_end + 1;
                var isPalindrome = true;
                for (loopIdx = 0; loopIdx < Math.floor((start + end) / 2) + (start + end) % 2; loopIdx++) {
                    if (s[start + loopIdx] != s[end - loopIdx]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome) {
                    // shift palindrome by 1 character
                    pal_start++;
                    pal_end++;
                } else {
                    reset = true;
                }
            } else if (s[pal_start - 1] == s[pal_end + 1]) {
                pal_start--;
                pal_end++;
                if (!hasDiffChars) hasDiffChars = s[pal_start - 1] != s[pal_end + 1];
                if (pal_end + 1 >= slen) reset = true;
            } else {
                reset = true;
            }
        }
        if (reset) {
            updateLongest();
            pal_start = pal_end = Math.floor((pal_start + pal_end) / 2);
            curr = pal_start;
            reset = false;
        }
    }
    return s.substring(longest_start, longest_end + 1);
};

function updateLongest() {
    if (longest_end - longest_start <= pal_end - pal_start) {
        longest_start = pal_start;
        longest_end = pal_end;
    }
}