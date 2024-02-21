#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <regex>

using namespace std;

#include "Solution.cpp"

void printTree(TreeNode *root) {
    TreeNode *temp = root;
    queue<TreeNode*> qNodes;
    qNodes.push(temp);
    for (int lvlNodes = 1; qNodes.size() > 0; lvlNodes *= 2) {
        for (int i = 0; i < lvlNodes && qNodes.size() > 0; i++) {
            temp = qNodes.front();
            qNodes.pop();
            if (temp) cout << temp->val << " ";
            if (temp && temp->left) qNodes.push(temp->left);
            if (temp && temp->right) qNodes.push(temp->right);
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    Solution soln;
    string line;
    int pval, qval, expected;
    TreeNode *root = nullptr, *p = nullptr, *q = nullptr, *res = nullptr;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    getline(fin, line);
    fin >> pval >> qval >> expected;
    regex patternMinFormat("-?\\d+,-?\\d+(,(-?\\d+|null))*");
    if (distance(sregex_iterator(line.begin(), line.end(), patternMinFormat), sregex_iterator()) == 0) {
        cout << "ERROR: Incorrect binary tree: " << line << endl;
        cout << "ERROR: Binary tree should have at least 2 nodes." << endl;
        exit(1);
    }
    regex patternNum("-?\\d+|null");
    sregex_token_iterator itr(line.begin(), line.end(), patternNum);
    queue<TreeNode*> qNodes;
    for (int lvlNodes = 1; itr != sregex_token_iterator(); lvlNodes *= 2) {
        TreeNode *parent = nullptr;
        for (int i = 0; i < lvlNodes && itr != sregex_token_iterator(); i++, itr++) {
            TreeNode *node = (*itr != "null") ? new TreeNode(atoi((*itr).str().c_str())) : nullptr;
            if (node && node->val == pval) p = node;
            if (node && node->val == qval) q = node;
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
    // printTree(root);
    cout << line << ": input" << endl;
    cout << pval << ": p" << endl;
    cout << qval << ": q" << endl;
    cout << expected << ": expected" << endl;
    res = soln.lowestCommonAncestor(root, p, q);
    cout << res->val << ": actual" << endl;
    return 0;
}