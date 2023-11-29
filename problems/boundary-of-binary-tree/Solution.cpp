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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result = {root->val};

        if (root->left) {
            // left boundary
            dfs(root->left, true, result);
        }
        if (root->right) {
            // right boundary
            boundary_done = false;
            vector<int> children;
            dfs(root->right, false, children);
            for (int i = children.size() - 1; i >= 0; i--) {
                result.emplace_back(children[i]);
            }
        }
        return result;
    }
private:
    bool boundary_done = false;

    // DFS to identify boundary nodes and leaf nodes
    void dfs(TreeNode *node, bool isLeftSub, vector<int>& values) {
        vector<int> result;
        if (node->left == nullptr && node->right == nullptr) {
            boundary_done = true; // boundary done
            values.emplace_back(node->val); // leaf value
            return;
        }
        if (!boundary_done) {
            // append boundary value
            values.emplace_back(node->val);
        }
        if (isLeftSub) {
            if (node->left) {
                dfs(node->left, isLeftSub, values);
            }
            if (node->right) {
                dfs(node->right, isLeftSub, values);
            }
        }
        else {
            if (node->right) {
                dfs(node->right, isLeftSub, values);
            }
            if (node->left) {
                dfs(node->left, isLeftSub, values);
            }
        }
    }
};