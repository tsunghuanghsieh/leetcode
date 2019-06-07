/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) {
    // hmmm... built-in string functions are faster than my implementation
    var chars = S.replace(/-/g, '').toUpperCase();
    var result = [];

    // only 1 group, no dash, simply return string.
    if (chars.length <= K) return chars;

    var start = chars.length % K;
    for (var i = 0; i < chars.length; i++) {
        if (i != 0 && (i - start) % K == 0) {
            result.push('-');
        }
        result.push(chars[i]);
    }
    return result.join('');
};

/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormattingSlower = function(S, K) {
    var char;
    var chars = [];
    var result = [];
    for (var i = 0; i < S.length; i++) {
        if (S[i] != '-') {
            // excluding dash from S
            char = S[i];
            if (S[i].match(/[a-z]/)) {
                // to upper case
                // A is 65, a is 97
                var charCode = S.charCodeAt(i) - 'a'.charCodeAt(0) + 'A'.charCodeAt(0);
                char = String.fromCharCode(charCode);
            }
            chars.push(char);
        }
    }

    // only 1 group, no dash, simply return joined string.
    if (chars.length <= K) return chars.join('');

    var start = chars.length % K;
    for (var i = 0; i < chars.length; i++) {
        if (i != 0 && (i - start) % K == 0) {
            result.push('-');
        }
        result.push(chars[i]);
    }
    return result.join('');
};