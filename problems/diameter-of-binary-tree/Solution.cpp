#include <iostream>

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
    // Using dfs, same as LC Editorial soln #1 (only soln).
    int diameterOfBinaryTree(TreeNode* root) {
        doWork(root);
        return diameter;
    }
private:
    int diameter = 0;

    int doWork(TreeNode *root) {
        int lenl = 0, lenr = 0;
        if (!root->left && !root->right) return 0;

        if (root->left) lenl = doWork(root->left) + 1;
        if (root->right) lenr = doWork(root->right) + 1;

        diameter = max(diameter, lenl + lenr);
        return max(lenl, lenr);
    }
};
