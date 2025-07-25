#include <fstream>
#include <iostream>
#include <queue>
#include <regex>

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

void printTree(TreeNode *root) {
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

int main(int argc, char** argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    fin >> line >> expected;
    TreeNode *root = parseInput(line);

    cout << line << ": root" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.diameterOfBinaryTree(root) << ": actual" << endl;

    return 0;
}
