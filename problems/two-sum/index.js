/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    arraySize = nums.length;
    // console.log("target " + target + '')
    for (var i = 0; i < arraySize; i++) {
        for (var j = i + 1; j < arraySize; j++) {
            var sorted = sortAbsolute(nums[i] + '', nums[j] + '');
            // sorted[0]: absolute bigger number
            // sorted[1]: absolute smaller number
            var sum = addNumbersStr(sorted[0], sorted[1]);
            // console.log("sum " + sum + " target " + target + '')
            if (sum == (target + '')) return [i, j];
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
