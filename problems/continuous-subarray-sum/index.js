/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
    var currSum = 0; // current sum of numbers
    var count = 0;
    var sums = new Map(); // count of current sum in array
    var result = false;

    for (var i = 0; i < nums.length; i++) {
        currSum += nums[i];

        if (currSum != nums[i] && currSum % k == 0) {
            return true;
        }

        if (nums[i] != k && sums.has(currSum % k)) {
            return true;
        }

        // count current sum in hashmap
        sums.set(currSum % k, 1);
    }

    return result;
};