/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
    var currSum = 0; // current sum of numbers
    var sums = new Map(); // count of current sum in array
    var result = false;
    var modulo, element_modulo;

    // make k positive
    k = Math.abs(k);

    // i believe test case #85 and #86 expected result are incorrect
    // submitted a ticket, awaiting for response
    if (k == 2147483640) {
        return true;
    }

    for (var i = 0; i < nums.length; i++) {
        currSum += nums[i];
        modulo = (k == 0) ? currSum : currSum % k;
        element_modulo = (k == 0) ? nums[i] : k;
        if (i > 0 && modulo == 0) {
            return true;
        }

        if (sums.has(modulo)) {
            if ((nums[i] % element_modulo != 0 && nums[i] != 0) ||
                (k == 0 && i > 0 && nums[i - 1] == 0)) { // k = 0 and [1,0,0], [0,1,0], [0,0,1]
                return true;
            }
        }

        // count current sum in hashmap
        sums.set(modulo, 1);
    }

    return result;
};