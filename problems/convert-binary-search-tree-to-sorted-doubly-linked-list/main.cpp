#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printDLL(Node* root) {
    Node *temp = root;
    cout << "[";
    while (temp) {
        cout << temp->val;
        if (temp->right != root) cout << ",";
        temp = temp->right;
        if (temp == root) break;
    }
    cout << "]: actual" << endl;
}
int main(int argc, char **argv) {
    Solution soln;
    string line, expected;
    Node *root = nullptr;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    getline(fin, line);
    queue<Node*> qNodes;
    regex patternNumber("-?\\d+|null");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (int lvlNodes = 1; itr != sregex_token_iterator(); lvlNodes *= 2) {
        Node *parent = nullptr;
        for (int i = 0; i < lvlNodes && itr != sregex_token_iterator(); i++, itr++) {
            Node *node = (*itr != "null") ? new Node(atoi((*itr).str().c_str())) : nullptr;
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
    getline(fin, expected);
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    Node *res = soln.treeToDoublyList(root);
    printDLL(res);
    return 0;
}