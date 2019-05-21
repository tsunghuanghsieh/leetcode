/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    var sum = 0;
    var count = 0;

    for (var i = 0, start = 0; i < nums.length; i++) {
        if (sum + nums[i] < k) {
            sum += nums[i];
        } else {
            if (sum + nums[i] == k) {
                count++;
            }
            sum -= nums[start];
            sum += nums[i];
            start++;
        }
    }

    return count;
};