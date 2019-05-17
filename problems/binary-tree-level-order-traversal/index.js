/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    var results = [];
    if (!root) return results;

    var nodes = [root];
    var rank = 0;
    while (nodes.length > 0) {
        var node_cnt = nodes.length;
        results[rank] = new Array();
        // enumerate all nodes at current level
        while (node_cnt > 0) {
            // pop the first in the queue
            var node = nodes.shift();
            results[rank].push(node.val);
            // append child nodes from left to right to the queue
            node.left && nodes.push(node.left);
            node.right && nodes.push(node.right);
            node_cnt--;
        }
        rank++;
    }
    return results;
};