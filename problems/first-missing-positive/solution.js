/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    var smallest_missing = 0;
    var idx_last_pos = 0, idx_ignore = 0;
    // separate positive numbers (low index) from number <= 0 (high index)
    for (idx_ignore = nums.length, idx_last_pos = nums.length - 1; idx_last_pos >= 0; idx_last_pos--) {
        if (nums[idx_last_pos] < 1) {
            var tmp = nums[idx_last_pos];
            nums[idx_last_pos] = nums[--idx_ignore];
            nums[idx_ignore] = tmp;
        }
    }

    // given n positive numbers in the array, say n = 4,
    // the smallest missing positive number will be one of 1, 2, 3 or 4, if any positive number is bigger than 4.
    // otherwise the smallest missing positive number will be 5.
    for (smallest_missing = 0; smallest_missing < idx_ignore; smallest_missing++) {
        // console.log("nums[" + smallest_missing + "] " + nums[smallest_missing]);
        // console.log("nums[Math.abs(nums[" + smallest_missing + "]) - 1] " + nums[Math.abs(nums[smallest_missing]) - 1]);

        // use value of nums[smallest_missing] for index of positive number in the array
        // so we know if we have seen 1-4 and set it to negative to indicate as seen.
        // second part of condition, in case of duplicate positive number, we will not operate on the negative value
        // otherwise, it will become positive again
        if (Math.abs(nums[smallest_missing]) - 1 < idx_ignore && nums[Math.abs(nums[smallest_missing]) - 1] > 0) {
            // set value to negative to indicate as visited
            nums[Math.abs(nums[smallest_missing]) - 1] = -nums[Math.abs(nums[smallest_missing]) - 1];
        }
        // console.log("nums[Math.abs(nums[" + smallest_missing + "]) - 1] " + nums[Math.abs(nums[smallest_missing]) - 1]);
    }

    for (smallest_missing = 0; smallest_missing < idx_ignore; smallest_missing++) {
        if (nums[smallest_missing] > 0) {
            // first missing positive found
            return smallest_missing + 1;
        }
    }

    return smallest_missing + 1;
}
