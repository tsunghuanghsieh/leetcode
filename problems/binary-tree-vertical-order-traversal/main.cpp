#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

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
    cout << "]: actual" << endl;
}

void printTreeNodes(TreeNode *root) {
    queue<TreeNode*> qNodes;
    qNodes.push(root);
    while (qNodes.size() > 0) {
        TreeNode *temp = qNodes.front();
        qNodes.pop();
        if (temp) cout << temp->val;
        else cout << "null";
        if (temp) qNodes.push(temp->left);
        if (temp) qNodes.push(temp->right);
        if (qNodes.size() > 0) cout << ",";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    TreeNode *root = nullptr;
    regex patternVal("\\d+|null");
    ifstream fin(argv[1]);
    string line, expected;
    getline(fin, line);
    cout << line << " : input" << endl;

    queue<TreeNode*> qNodes;
    sregex_token_iterator itr(line.begin(), line.end(), patternVal);
    // Build tree from input
    for (int lvlNodes = 1; itr != sregex_token_iterator(); lvlNodes *= 2) {
        TreeNode *parent = nullptr;
        // Construct nodes at the current level
        for (int i = 0, left = 1; i < lvlNodes && itr != sregex_token_iterator(); i++) {
            TreeNode *child = (*itr != "null") ? new TreeNode(atoi((*itr).str().c_str())) : nullptr;
            if (child) qNodes.push(child);
            if (root == nullptr) {
                root = child;
                itr++;
                break;
            }

            if (left % 2 == 1 && qNodes.size() > 0) {
                parent = qNodes.front();
                qNodes.pop();
            }
            if (parent == nullptr) continue;

            if (left % 2) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            left++;
            itr++;
        }
    }
    printTreeNodes(root);

    fin >> expected;
    cout << expected << " : expected" << endl;
    printResult(soln.verticalOrder(root));
    return 0;
}