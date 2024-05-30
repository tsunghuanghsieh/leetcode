#include <fstream>
#include <iostream>
#include <queue>
#include <regex>

using namespace std;

#include "Solution.cpp"

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

int main(int argc, char **argv)
{
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;

    TreeNode *root = nullptr;
    queue<TreeNode*> qNodes;
    regex patternNum("\\d|null");
    sregex_token_iterator itr(line.begin(), line.end(), patternNum);
    for (int lvlNodes = 1; itr != sregex_token_iterator(); lvlNodes *= 2) {
        TreeNode *parent = nullptr;
        for (int i = 0; i < lvlNodes && itr != sregex_token_iterator(); i++, itr++) {
            TreeNode *node = (*itr != "null") ? new TreeNode(atoi((*itr).str().c_str())) : nullptr;
            qNodes.push(node);
            if (!root) {
                root = node;
                continue;
            }
            if (i % 2 == 0) {
                parent = qNodes.front();
                qNodes.pop();
                if (parent) parent->left = node;
            }
            else {
                if (parent) parent->right = node;
            }
        }
    }

    printTree(root);
    cout << soln.sumNumbers(root) << ": actual" << endl;
    return 0;
}