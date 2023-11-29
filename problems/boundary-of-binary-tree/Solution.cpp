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
            vector<int> children = dfs(root->left, true);
            result.insert(result.end(), children.begin(), children.end());
        }
        if (root->right) {
            // right boundary
            boundary_done = false;
            vector<int> children = dfs(root->right, false);
            for (int i = children.size() - 1; i >= 0; i--) {
                result.emplace_back(children[i]);
            }
        }
        return result;
    }
private:
    bool boundary_done = false;

    // DFS to identify boundary nodes and leaf nodes
    vector<int> dfs(TreeNode *node, bool isLeftSub) {
        vector<int> result;
        if (node->left == nullptr && node->right == nullptr) {
            boundary_done = true; // boundary done
            return {node->val}; // leaf value
        }
        if (!boundary_done) {
            // append boundary value
            result.emplace_back(node->val);
        }
        if (isLeftSub) {
            if (node->left) {
                vector<int> children = dfs(node->left, isLeftSub);
                result.insert(result.end(), children.begin(), children.end());
            }
            if (node->right) {
                vector<int> children = dfs(node->right, isLeftSub);
                result.insert(result.end(), children.begin(), children.end());
            }
        }
        else {
            if (node->right) {
                vector<int> children = dfs(node->right, isLeftSub);
                result.insert(result.end(), children.begin(), children.end());
            }
            if (node->left) {
                vector<int> children = dfs(node->left, isLeftSub);
                result.insert(result.end(), children.begin(), children.end());
            }
        }
        return result;
    }
};