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
    var nodes = [];
    var values = [];
    var leftDone = false;
    var rightDone = false;
    //     1
    //    /  \
    //   2    3
    //  / \   /
    // 4   5 6
    // inorder traveral: 4 2 5 1 6 3
    nodes.push(root);
    while (nodes.length != 0) {
        while (root.left != null && leftDone != true) {
            nodes.push(root.left);
            root = root.left;
        }
        values.push(root.val);
        nodes.pop();
        leftDone = true;
        console.log('value ' + root.val);
        if (root.right != null) {
            nodes.push(root.right);
            root = root.right;
            leftDone = false;
            continue;
        }
        root = nodes[nodes.length - 1];
        // rightDone = true;
    }
    console.log(values)
    return values;
};
