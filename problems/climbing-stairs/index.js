/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    var n1 = 1;
    var n2 = 2;
    if (n == 1) return n1;
    if (n == 2) return n2;

    for (var i = 3; i < n; i++) {
        n2 = n2 + n1;
        n1 = n2 - n1;
    }
    return n1 + n2;
};