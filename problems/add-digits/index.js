/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    var sum = 0;
    while (num >= 10) {
        sum = 0;
        sum = sum + num % 10;
        // console.log(sum)
        while (Math.floor(num / 10) > 0) {
            num = Math.floor(num / 10);
            sum = sum + num % 10;
        }
        num = sum;
    }
    if (sum > 0) num = sum;
    return num;
};