#include <iostream>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return res;
        dfs(root, targetSum, vector<int>());
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(TreeNode *root, int targetSum, vector<int> v) {
        v.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(v);
        }
        if (root->left) dfs(root->left, targetSum - root->val, v);
        if (root->right) dfs(root->right, targetSum - root->val, v);
    }
};
