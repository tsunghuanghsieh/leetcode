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

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

// Debug
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

void printUsage() {
    cout << "./a.out tests/<test_case_name>" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    string input, expected;
    vector<int> result;
    if (argc != 2) printUsage();
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    fin >> input >> expected;
    TreeNode *root = parseInput(input);
    cout << input << ": input" << endl;
    cout << expected << ": expected" << endl;
    result = soln.rightSideView(root);
    printResult(result);
    return 0;
}
