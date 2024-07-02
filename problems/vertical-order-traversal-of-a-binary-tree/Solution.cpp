#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
    // This problem requires to order the result by column, row and value. Since c++ doesn't have a built-in class
    // for triplet, I decided to use separate built-in data types to keep code easier to understand, and minimize
    // sorting, (log n/k) where n is the number of nodes and k is the number of columns, instead of (log n).
    // This approach is LC Editorial solution 2, BSF/DSF with partition sorting.
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> nodes_dist;   // col, row, values
        queue<TreeNode*> qNodes;
        queue<int> qCols;

        qNodes.push(root);
        qCols.push(0);
        int curr_lvl = 0, curr_size = 1;
        while (curr_size > 0) {
            TreeNode *currNode = qNodes.front();
            int col = qCols.front();
            qNodes.pop();
            qCols.pop();
            curr_size--;
            nodes_dist[col][curr_lvl].emplace_back(currNode->val);
            if (currNode->left) {
                qNodes.push(currNode->left);
                qCols.push(col - 1);
            }
            if (currNode->right) {
                qNodes.push(currNode->right);
                qCols.push(col + 1);
            }
            if (curr_size == 0) {
                curr_lvl++;
                curr_size = qNodes.size();
            }
        }
        for (auto [_, lvl_nodes_val] : nodes_dist) {
            vector<int> vals;
            for (auto [_, nodes_vals] : lvl_nodes_val) {
                sort(nodes_vals.begin(), nodes_vals.end());
                vals.insert(vals.end(), nodes_vals.begin(), nodes_vals.end());
            }
            res.emplace_back(vals);
        }
        return res;
    }
};
