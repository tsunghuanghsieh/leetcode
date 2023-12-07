#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

void printAncestry(Node *node) {
    Node *curr = node;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->parent;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    regex patternVal("-?\\d+|null");
    int val_p, val_q, expected;
    ifstream fin(argv[1]);
    string line;
    getline(fin, line);
    cout << line << " : input" << endl;

    sregex_token_iterator itr(line.begin(), line.end(), patternVal);

    fin >> val_p >> val_q >> expected;
    cout << "p val: " << val_p << endl << "q val: " << val_q << endl;

    // Build tree from input
    Node *root = nullptr, *p, *q;
    queue<Node*> qNodes;
    for (int lvlNodes = 1; itr != sregex_token_iterator(); lvlNodes *= 2) {
        Node *parent = nullptr;
        // Construct nodes at the current level
        for (int i = 0, left = 1; i < lvlNodes && itr != sregex_token_iterator(); i++) {
            Node *child = nullptr;
            if (*itr != "null") {
                child = new Node();
                child->val = atoi((*itr).str().c_str());
                if (child->val == val_p) p = child;
                if (child->val == val_q) q = child;
            }
            /* if (child) */ qNodes.push(child);
            if (root == nullptr) {
                root = child;
                itr++;
                continue;
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
            if (child) child->parent = parent;
            left++;
            itr++;
        }
    }

    cout << expected << " : expected" << endl;
    Node* result = soln.lowestCommonAncestor(p, q);
    Node* result2 = soln2.lowestCommonAncestor(p, q);
    cout << result->val << " : actual soln" << endl;
    cout << result2->val << " : actual soln2" << endl;
    return 0;
}