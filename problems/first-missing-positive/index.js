/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    var smallest_missing = 1;
    var smallest_number = 0;
    var largest_number = 0;
    var leftBound = 0, rightBound = 0;
    var last_smallest = 0;
    var positive_count = 0;
    for (var i = 0; i < nums.length; i++) {
        // skip 0 and negative numbers
        if (nums[i] <= 0) continue;

        positive_count++;
        // find the smallest number in the array
        if (smallest_number == 0 || nums[i] < smallest_number) {
            if (leftBound == 0 && rightBound == 0) {
                leftBound = rightBound = nums[i];
                if (leftBound > 1) {
                    smallest_missing = leftBound - 1;
                } else {
                    smallest_missing = rightBound + 1;
                }
                console.log("leftBound " + leftBound + " rightBound " + rightBound + " smallest_missing " + smallest_missing);
            }
            last_smallest = smallest_number;
            smallest_number = nums[i];
        }
        if (nums[i] > largest_number) largest_number = nums[i];
        console.log("nums[i] " + nums[i]);
        if (nums[i] == rightBound + 1) {
            rightBound++;
            if (rightBound == smallest_missing) smallest_missing++;
        }
        if (nums[i] == leftBound - 1) {
            if (leftBound > 2) {
                leftBound--;
                smallest_missing--;
            } else {
                smallest_missing = rightBound + 1;
            }
        }
        console.log("leftBound " + leftBound + " rightBound " + rightBound + " smallest_missing " + smallest_missing);
        if (smallest_number == smallest_missing) {
            if (smallest_number > 2) {
                smallest_missing = smallest_number - 1;
            } else {
                smallest_missing = rightBound + 1;
            }
        }
    }
    if (smallest_number != 1) return 1;
    if (largest_number == nums.length && nums.length == positive_count) return largest_number + 1;
    return smallest_missing;
};