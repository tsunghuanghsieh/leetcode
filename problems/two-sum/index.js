/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var mapNums = new Map();
    nums.forEach(function(num, idx) {
        mapNums.set(num, idx); // keep the last index of duplicate integers in the array
    })
    for (var i = 0; i < nums.length; i++) {
        var diff = target - nums[i];
        // find diff in map, and make sure it is a different index in the array
        if (mapNums.has(diff) && i != mapNums.get(diff)) {
            return [i, mapNums.get(diff)];
        }
    }
};

// If the input contains a lot of duplicate integers, this may run slightly faster since
// the second loop looks at unique keys. The code however is somewhat convoluted.
var twoSum = function(nums, target) {
    arraySize = nums.length;
    var numsMap = new Map();
    // console.log("target " + target + '')
    for (var i = 0; i < arraySize; i++) {
        // some test case will have duplicate integers in the array and cause a key collision
        // so value in the Map will be an array of indices
        if (numsMap.has(nums[i])) {
            // collision
            var indices = numsMap.get(nums[i]);
            indices.push(i);
        } else {
            var indices = [i];
        }
        numsMap.set(nums[i], indices);
    }
    for (const [key, value] of numsMap) {
        var diff = target - key;
        // console.log(key + ' ' + value + ' diff ' + diff + ' ' + numsMap.get(diff));
        if (numsMap.has(diff)) {
            var indices = numsMap.get(diff);
            var len = indices.length;

            // unique, one and only in the array
            if (len == 1) {
                if (numsMap.get(key) == numsMap.get(diff)) {
                    // [key, value] and [diff, value] point to the same element in the array
                    continue;
                }
            }
            // diff is the same as key (duplicate integers in the array)
            // given there is exactly one solution, it can be only two of them
            if (len == 2) {
                return numsMap.get(diff);
            }
            // diff is the same as key (duplicate integers in the array)
            // given there is exactly one solution, it can be only two of them
            // this should never happen
            if (len > 2) {
                console.log('This should never happen. More than 1 solution found ' + indices)
                continue;
            }

            // unique number
            // console.log(key + ' ' + value + ' diff ' + diff + ' ' + numsMap.get(diff));
            return [value, indices];
        }
    }
};

// take 2 numbers in string and return the sum
function addNumbersStr(absBigger, absSmaller) {
    var sum = '';
    var ops = (absBigger[0] == '-') + (absSmaller[0] == '-');
    // console.log('ops ' + ops)
    var isSumNegative = absBigger[0] == '-';
    var len_bigger = absBigger.length - (absBigger[0] == '-');      // length without minus
    var len_smaller = absSmaller.length - (absSmaller[0] == '-');   // length without minus
    var carryover = 0;
    var iterator = 0;

    // console.log(absBigger);
    // console.log(absSmaller);
    absBigger = absBigger.substring((absBigger[0] == '-') ? 1 : 0);      // strip minus, if any.
    absSmaller = absSmaller.substring((absSmaller[0] == '-') ? 1 : 0);   // strip minus, if any.
    // console.log(absBigger);
    // console.log(absSmaller);
    for (iterator = 0; iterator < len_bigger && iterator < len_smaller; iterator++) {
        // start from least significant digit of both numbers
        var a = (len_bigger > iterator) ? parseInt(absBigger[len_bigger - (iterator + 1)]) : 0;
        var b = (len_smaller > iterator) ? parseInt(absSmaller[len_smaller - (iterator + 1)]) : 0;
        // console.log('a ' + a + ' b ' + b + ' carryover ' + carryover + ' iterator ' + iterator)
        // ops is 1 only when only one of the 2 numbers is negative
        // pos + pos, neg + neg, pos - neg, neg - pos
        var temp = (ops != 1) ? a + b + carryover : a - b + carryover;
        // console.log('temp ' + temp);
        carryover = (temp != 0) ? ((temp > 0) ? Math.floor(temp / 10) : -1) : 0;   // get carryover in whole number
        temp = (temp < 0) ? temp + 10 : temp;   // carryover is negative. borrow 10 from left.
        // console.log('carryover ' + carryover);
        temp = Math.abs(temp) % 10; // get remainder
        sum += temp; // concat the sum of numbers in reverse order
    }
    // console.log("sum " + sum + ' iterator ' + iterator);
    while (carryover != 0) {
        // there is a carryover in the most significant digit
        var a = (len_bigger > iterator) ? parseInt(absBigger[len_bigger - (iterator + 1)]) : 0;
        var b = (len_smaller > iterator) ? parseInt(absSmaller[len_smaller - (iterator + 1)]) : 0;
        var temp = (ops != 1) ? a + b + carryover : a - b + carryover;
        carryover = (temp != 0) ? ((temp > 0) ? Math.floor(temp / 10) : -1) : 0;   // get carryover in whole number
        temp = (temp < 0) ? temp + 10 : temp;   // carryover is negative. borrow 10 from left.
        temp = Math.abs(temp) % 10; // get remainder
        sum += temp;
        iterator++;
    }
    // console.log("sum " + sum + ' iterator ' + iterator);
    // console.log("len_bigger " + len_bigger + ' len_smaller ' + len_smaller);
    var prefix = (len_bigger > iterator) ? absBigger.substring(0, len_bigger - iterator) :
                    (len_smaller > iterator) ? absSmaller.substring(0, len_smaller - iterator) : '';
    var reversed = '';
    for (var i = 0; i < sum.length; i++) {
        reversed = reversed + sum[sum.length - (i + 1)];
    }
    // console.log("prefix " + prefix + " reversed " + reversed);
    if (prefix == '') {
        for (var i = 0; i < reversed.length; i++) {
            if (reversed[i] != '0') {
                // strip leading zeros
                reversed = reversed.substring(i);
                break;
            }
            // all zeros
            if (i + 1 == reversed.length) reversed = '0';
        }
        // console.log("reversed " + reversed);
    }
    // console.log('returned ' + ((isSumNegative && (prefix != '' || reversed != '0')) ? '-' : '') + prefix + reversed);
    return ((isSumNegative && (prefix != '' || reversed != '0')) ? '-' : '') + prefix + reversed;
}

// take 2 numbers in string and return them in absolute magnitude in an array
// array[0]: absolute bigger number
// array[1]: absolute smaller number
function sortAbsolute(string_i, string_j) {
    var len_i = string_i.length - (string_i[0] == '-');
    var len_j = string_j.length - (string_j[0] == '-');

    if (len_i > len_j) {
        return [string_i, string_j];
    } else if (len_i < len_j) {
        return [string_j, string_i];
    } else {
        var iterator = 0;
        var str_i = string_i.substring((string_i[0] == '-') ? 1 : 0);   // strip minus, if any.
        var str_j = string_j.substring((string_j[0] == '-') ? 1 : 0);   // strip minus, if any.
        for (iterator = 0; iterator < len_i; iterator++) {
            if (parseInt(str_i[iterator]) > parseInt(str_j[iterator]))
                return [string_i, string_j];
            if (parseInt(str_i[iterator]) < parseInt(str_j[iterator]))
                return [string_j, string_i];
        }
        // they are equal, return first one
        return [string_i, string_j];
    }
}
