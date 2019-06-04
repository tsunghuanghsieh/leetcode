/**
 * @param {number[]} tree
 * @return {number}
 */
var totalFruit = function(tree) {
    var idx_fruit2 = 0;
    var fruits = [ tree[0], -1 ];
    var longest = 1;
    var current = 1;

    // handle special cases
    if (tree.length <= 2) return tree.length;

    for (var i = 1; i < tree.length; i++) {
        // only 1 fruit so far
        if (fruits[1] == -1) {
            if (tree[i] == fruits[0]) { // still 1 fruit
                current++;
            } else { // 2 fruits now
                idx_fruit2 = i;
                fruits[1] = tree[i];
                current++;
            }
            continue;
        }
        if (tree[i] == fruits[1]) {
            // found 2nd fruit, increment and continue
            current++;
            continue;
        } else {
            if (fruits[0] != tree[i]) {
                // 3rd fruit encounter
                if (current > longest) {
                    longest = current;
                }
                current = i - idx_fruit2;
            }
            // update fruit order
            fruits[0] = fruits[1];
            fruits[1] = tree[i];
            idx_fruit2 = i;
            current++;
            continue;
        }
    }
    return (current > longest) ? current : longest;
};