/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    var n1 = 1;
    var n2 = 2;
    if (n == 1) return n1;
    if (n == 2) return n2;

    // Similar to Fibonacci number
    // number of distinct ways for steps n is sum of that for step (n - 2) and (n - 1)
    for (var i = 3; i < n; i++) {
        n2 = n2 + n1; // at (n - 1) steps
        n1 = n2 - n1; // at (n - 2) steps
    }
    return n1 + n2;
};