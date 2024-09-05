#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

TreeNode* parseInput(string input) {
    regex patternVal("-?\\d+|null");
    TreeNode *root = nullptr;
    queue<TreeNode*> qNodes;
    sregex_token_iterator itr(input.begin(), input.end(), patternVal);
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
    return root;
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
    cout << "]: actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    int targetSum;
    fin >> line >> targetSum >> expected;

    TreeNode *root = parseInput(line);

    cout << line << ": line" << endl;
    cout << targetSum << ": targetSum" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.pathSum(root, targetSum));
    return 0;
}
