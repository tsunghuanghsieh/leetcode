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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> qNodes;
        int lvl = 1;
        qNodes.push(make_pair(root, 0));
        while (qNodes.size() > 0) {
            int cntNullptr = 0;
            for (int i = 0, offset = 0; i < lvl; i++) {
                pair<TreeNode*, int> curr = qNodes.front();
                qNodes.pop();
                if (curr.first == nullptr) {
                    cntNullptr++;
                    qNodes.push(make_pair(curr.first, -1));
                    qNodes.push(make_pair(curr.first, -1));
                    continue;
                }
                if (curr.first && curr.second < 0 && offset == 0) {
                    result.insert(result.begin(), vector<int>({curr.first->val}));
                    offset++;
                }
                else if (curr.second + offset >= result.size() || result.size() == 0) {
                    result.emplace_back(vector<int>({curr.first->val}));
                }
                else {
                    result[curr.second + offset].emplace_back(curr.first->val);
                }
                qNodes.push(make_pair(curr.first->left, curr.second - 1 + offset));
                qNodes.push(make_pair(curr.first->right, curr.second + 1 + offset));
            }
            if (cntNullptr == lvl) break;
            lvl *= 2;
        }
        return result;
    }
private:
    void printLevel(queue<pair<TreeNode*, int>>& qNodes) {
        int size = qNodes.size();
        for (int i = 0; i < size; i++) {
            pair<TreeNode*, int> curr = qNodes.front();
            qNodes.pop();
            qNodes.push(curr);
            if (curr.first == nullptr) cout << "null ";
            else cout << curr.first->val << " ";
        }
        cout << endl;
    }
    void printResult(vector<vector<int>> result) {
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << "[";
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1) cout << ",";
            }
            cout << "]";
            if (i < result.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
};