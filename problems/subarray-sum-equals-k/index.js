/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    var currSum = 0; // current sum of numbers
    var count = 0;
    var sums = new Map(); // count of current sum in array

    for (var i = 0; i < nums.length; i++) {
        currSum += nums[i];

        if (currSum == k) {
            count++;
        }

        if (sums.has(currSum - k)) {
            // find number of subarrays that has the sum k, stored at currSum - k.
            count += sums.get(currSum - k);
        }

        // count current sum in hashmap
        if (sums.has(currSum)) {
            // increment
            sums.set(currSum, sums.get(currSum) + 1);
        } else {
            // new
            sums.set(currSum, 1);
        }
    }

    return count;
};