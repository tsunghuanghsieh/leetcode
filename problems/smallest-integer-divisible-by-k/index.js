/**
 * @param {number} K
 * @return {number}
 */
var smallestRepunitDivByK = function (K) {
    // 1 <= K <= 10^5 (100000)

    // short-circuiting for even numbers and least significant digit 5.
    // no multiplication will result with 1 in the least significant digit.
    if (K % 2 == 0) return -1;
    if (K % 5 == 0) return -1;
    // special case for K is 1
    if (K == 1) return 1;

    // only integers with 1, 3, 7 and 9 in the least significant digit will get to this point
    // 1 * 1 = 1
    // 3 * 7 = 21
    // 7 * 3 = 21
    // 9 * 9 = 81
    var strDivisor = [];
    var idx_d = 0; // current index of strDivisor being operated on
    var product = 0;
    var carryover = Math.floor(product / 10);
    while (true) {
        var multiplyer;
        for (multiplyer = 0; multiplyer < 10; multiplyer++) {
            product = K * multiplyer + carryover;
            if (product % 10 == 1) {
                strDivisor[idx_d] = multiplyer;
                carryover = Math.floor(product / 10);
                idx_d++;
                break;
            }
        }
        if (multiplyer == 10) {
            // no solution
            return -1;
        }
        if (multiplyer == 0 && carryover == 0) {
            // done
            return idx_d;
        }
    }
};