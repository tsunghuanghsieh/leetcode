/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var indices = [];

    // Was initially thinking of not sorting the input array (to avoid incurring O(nlogn) runtime)
    // and using extra map(nums[i], [i...])) to keep track of nums[].
    // We then iterate the map (deleting key1 from map) and find among the rest of keys whose sum is (key1 = 0 - sum).
    // [-2,2,-1,0,-4,0,2,2,-3,0]
    // -2, [0]
    //  2, [1, 6, 7]
    // -1, [2]
    //  0, [3, 5, 9]
    // -4, [4]
    // -3, [8]
    // For cases like [-4, 2, 2], [0, 0, 0]
    // Code will need to not only look at the key of the map, but also the length of indices in map value.
    // Hence, code is more convoluted.
    // (e.g. https://github.com/tsunghuanghsieh/leetcode/blob/d3492b90164bf2b6a0b3ef5b99edc21723cce16c/problems/two-sum/index.js#L25).

    // this will incur O(nlogn) runtime
    nums.sort(function (a, b) {
        // this is needed, because the values are treated as strings by default
        return a - b;
    });

    for (var i = 0; i < nums.length - 2; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue; // duplicate found
        // since the array is now sorted, we can traverse from 2 ends to find the sum
        var first = i + 1;
        var last = nums.length - 1;

        while (first < last) {
            var sum = nums[first] + nums[last];
            if (nums[i] == 0 - sum) {
                var triplet = [nums[i], nums[first], nums[last]];
                indices.push(triplet);
                last--;
                while (nums[last] == nums[last + 1]) last--;
            } else if (nums[i] > 0 - sum) {
                last--;
            } else {
                first++;
            }
        }
    }

    return indices;
};
