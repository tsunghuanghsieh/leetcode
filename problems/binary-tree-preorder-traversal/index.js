/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    var stack = [];
    var values = [];

    // special case
    if (root == null) return stack;

    do {
        // values.push(root.val);
        while (root != null) {
            values.push(root.val);
            // traverse left subtree of current node
            stack.push(root);
            root = root.left;
        }
        root = stack[stack.length - 1];
        // pop current "in" node from stack
        stack.pop();
        // traverse right subtree of current node
        root = root.right;
    } while (root || stack.length > 0);

    return values;
};