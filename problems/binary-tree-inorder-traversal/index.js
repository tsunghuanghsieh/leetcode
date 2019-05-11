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
var inorderTraversal = function(root) {
    var nodes = []; // stack for traversal
    var values = []; // output
    //     1
    //    /  \
    //   2    3
    //  / \   /
    // 4   5 6
    // inorder traveral: 4 2 5 1 6 3
    while (root || nodes.length > 0) {
        while (root != null) {
            // push current node to top of stack
            nodes.push(root);
            // traverse left node tree
            root = root.left;
        }
        // root is now null (no more left node), get top node in stack
        root = nodes[nodes.length - 1];
        values.push(root.val);
        nodes.pop();
        // traverse right node tree
        root = root.right;
    }
    return values;
};
