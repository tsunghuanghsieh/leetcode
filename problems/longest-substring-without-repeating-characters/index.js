/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var charLastSeenMap = new Map();
    var longest = 0;
    var strStartIdx = 0;
    for (var idx = 0; idx < s.length; idx++) {
        if (charLastSeenMap.has(s[idx]) && charLastSeenMap.get(s[idx]) > strStartIdx) {
            // we have seen this character before, update substring starting index
            strStartIdx = charLastSeenMap.get(s[idx]);
        }
        charLastSeenMap.set(s[idx], idx + 1);

        if (longest < idx + 1 - strStartIdx) {
            longest = idx + 1 - strStartIdx;
        }
    }
    return longest;
};