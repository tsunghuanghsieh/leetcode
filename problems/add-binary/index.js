/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    var result = [];
    var digitA = 0;
    var digitB = 0;
    var carry = 0;
    for (var i = 0; i < a.length || i < b.length; i++) {
        digitA = (i >= a.length) ? 0 : parseInt(a[a.length - 1 - i]);
        digitB = (i >= b.length) ? 0 : parseInt(b[b.length - 1 - i]);
        result.unshift((digitA + digitB + carry) % 2);
        carry = Math.floor((digitA + digitB + carry) / 2);
        // console.log('sum ' + sum);
        // console.log('carry ' + carry);
        // console.log('result ' + result);
    }
    if (carry == 1) result.unshift(carry);
    // console.log(result);
    return result.join('');
};