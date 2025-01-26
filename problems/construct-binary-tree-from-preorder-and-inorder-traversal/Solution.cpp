#include <iostream>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, TreeNode *> um;
        TreeNode *root = nullptr, *parent = nullptr;
        for (int p = 0, i = 0, d = 0 /* left == 0, right > 0 */; p < preorder.size(); p++) {
            TreeNode *node = new TreeNode(preorder[p]);
            if (root == nullptr) root = parent = node;
            // preorder[p] == inorder[i], no left child at this node, the next node is in right subtree
            if (preorder[p] == inorder[i]) {
                if (root != node) {
                    if (d == 0) parent->left = node;
                    else parent->right = node;
                    parent = node;
                }
                d = ++i;
            }
            else {
                // inorder[i] in unordered_map, the next node is in right subtree of some parent node
                if (um.count(inorder[i])) {
                    parent = um[inorder[i]];
                    d = ++i;
                    p--;   // p shouldn't increment in this case, to counteract the for stmt
                }
                else {
                    if (root != node) {
                        if (d == 0) parent->left = node;
                        else parent->right = node;
                        parent = node;
                        d = 0;
                    }
                }
            }
            um[preorder[p]] = node;
        }
        return root;
    }
};
