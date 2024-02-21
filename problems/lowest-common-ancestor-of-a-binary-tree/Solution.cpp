#include <iostream>
#include <unordered_set>

using namespace std;

#ifndef __CLASS_NODE
#define __CLASS_NODE
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool bFound = false;
        return dfs(root, p, q, bFound);
    }

    TreeNode* dfs(TreeNode *root, TreeNode *p, TreeNode *q, bool &bFound) {
        TreeNode *res = nullptr;
        bool bFoundinLeft = false, bFoundinRight = false, bFoundinRoot = false;
        if (root) {
            if (root->left) res = dfs(root->left, p, q, bFoundinLeft);
            if (res) return res;
            if (root->right) res = dfs(root->right, p, q, bFoundinRight);
            if (res) return res;
            if (root->val == p->val || root->val == q->val) bFoundinRoot = true;
            if (bFoundinLeft && bFoundinRight || ((bFoundinLeft || bFoundinRight) && bFoundinRoot)) {
                return root;
            }
            bFound = bFoundinRoot || bFoundinLeft || bFoundinRight;
        }
        return res;
    }
};
