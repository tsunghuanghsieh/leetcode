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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int qsize = q.size();
        while (qsize > 0) {
            TreeNode *node = q.front();
            q.pop();
            qsize--;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (qsize == 0) {
                res.emplace_back(node->val);
                qsize = q.size();
            }
        }
        return res;
    }
};
