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

    // var stringK = [];
    // var lenK = 0;
    // while (Math.floor(K / 10) > 0) {
    //     stringK[lenK++] = K % 10;
    //     K = Math.floor(K / 10);
    // }
    // stringK[lenK] = K;

    // only integers with 1, 3, 7 and 9 in the least significant digit will get to this point
    // 1 * 1 = 1
    // 3 * 7 = 21
    // 7 * 3 = 21
    // 9 * 9 = 81
    // var quotients = [-1, 1, -1, 7, -1, -1, -1, 3, -1, 9];
    // var divisor = [quotients[stringK[0]]]; // initialize least significant digit of divisor
    // var idx_k = 1; // current index of stringK being operated on
    // var product = stringK[0] * divisor[0];
    var strDivisor = [];
    var idx_d = 0; // current index of strDivisor being operated on
    var idx_k; // current index of stringK being operated on
    var product = 0;
    var carryover = Math.floor(product / 10);
    console.log("before while K " + K);
    console.log("before while product " + product);
    console.log("before while carryover " + carryover);
    while (true) {
        var multiplyer;
        for (multiplyer = 0; multiplyer < 10; multiplyer++) {
            // product = stringK[idx_k] * multiplyer + carryover;
            product = K * multiplyer + carryover;
            console.log("multiplier " + multiplyer + " product " + product);
            if (product % 10 == 1) {
                console.log("product " + product);
                strDivisor[idx_d] = multiplyer;
                carryover = Math.floor(product / 10);
                console.log("carryover " + carryover);
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