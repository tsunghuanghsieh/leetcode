/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var length = matrix.length;
    var temp;

    for (var lvl = 0; lvl < Math.floor(length / 2); lvl++) {
        for (var i = lvl; i < length - 1 - lvl; i++) {
            temp = matrix[lvl][i];
            // update top row
            matrix[lvl][i] = matrix[length - 1 - i][lvl];
            // update left column
            matrix[length - 1 - i][lvl] = matrix[length - 1 - lvl][length - 1 - i];
            // update bottom row
            matrix[length - 1 - lvl][length - 1 - i] = matrix[i][length - 1 - lvl];
            // update right column
            matrix[i][length - 1 - lvl] = temp;
        }
    }

    return matrix;
};