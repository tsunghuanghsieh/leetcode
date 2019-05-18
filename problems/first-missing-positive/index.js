/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    var smallest_number = 0;
    var positive_count = 0;
    var numsMap = new Map();
    for (var i = 0; i < nums.length; i++) {
        // skip 0 and negative numbers
        if (nums[i] <= 0) continue;
        // number of positive numbers in array
        positive_count++;
        // find the smallest number in the array
        if (smallest_number == 0 || nums[i] < smallest_number) smallest_number = nums[i];
    }
    if (smallest_number != 1) return 1;

    for (var i = 0; i < nums.length; i++) {
        // skip 0, negative numbers, and numbers that's out of possible range
        if (nums[i] <= 0 || nums[i] > smallest_number + positive_count - 1) continue;

        numsMap.set(nums[i], i);
    }

    for (var i = 1; i <= positive_count; i++) {
        // find the first missing number in the hashmap
        if (!numsMap.has(smallest_number + i)) {
            return smallest_number + i;
        }
    }

    // the missing number is 1 + largest positive number
    return smallest_number + positive_count;
};