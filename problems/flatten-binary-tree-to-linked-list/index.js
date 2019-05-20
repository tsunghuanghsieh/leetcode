/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    var queue = [];
    var sequence = []
    var temp = root;

    if (!root) return root;
    while (temp || queue.length > 0) {
        while (temp) {
            queue.push(temp);
            sequence.push(temp.val);
            temp = temp.left;
        }
        temp = queue.pop();
        temp = temp.right;
    }

    var start = root;
    for (var i = 1; i < sequence.length; i++) {
        var node = new TreeNode(sequence[i]);
        start.right = node;
        start = start.right;
    }
    root.left = null;
};