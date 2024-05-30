#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        preorder(root, 0);
        return sum;
    }
private:
    // Recursive Preorder Traversal
    void preorder(TreeNode *node, int num) {
        if (!node->left && !node->right) {
            sum += num + node->val;
            return;
        }
        if (node->left) preorder(node->left, (num + node->val) * 10);
        if (node->right) preorder(node->right, (num + node->val) * 10);
    }
};

//
// LC Editorial shows Morris Preorder Traversal that uses temporary link from right child to current root.
// It uses constant space O(1) instead of O(h) where h is the height of the tree in recursive and iterative traversal.
//
