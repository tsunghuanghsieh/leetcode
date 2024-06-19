#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printGraph(Node *node, bool result) {
    map<int, Node *> exists;
    Node *newNode = node;
    deque<Node *> dq({node});
    while (dq.size() > 0) {
        Node *curr = dq.front();
        dq.pop_front();
        exists[curr->val] = curr;
        for (int i = 0; i < curr->neighbors.size(); i++) {
            if (exists.find(curr->neighbors[i]->val) == exists.end()) dq.push_back(curr->neighbors[i]);
            exists[curr->neighbors[i]->val] = curr->neighbors[i];
        }
    }
    cout << "[";
    for (int idx = 1; idx <= exists.size(); idx++) {
        cout << "[";
        for (int i = 0; i < exists[idx]->neighbors.size(); i++) {
            cout << exists[idx]->neighbors[i]->val;
            if (i < exists[idx]->neighbors.size() - 1) cout << ",";
        }
        cout << "]";
        if (idx < exists.size()) cout << ",";
    }
    cout << "]";
    cout << ((result) ? ": actual" : "") << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string input;
    fin >> input;

    Node *head = nullptr;
    map<int, Node *> exists;
    regex patternNumberGroup("\\d+(,\\d+)*");
    sregex_token_iterator itrNode(input.begin(), input.end(), patternNumberGroup);
    for (int val = 1; itrNode != sregex_token_iterator(); val++, itrNode++) {
        Node *curr = (exists.find(val) == exists.end()) ? new Node(val) : exists[val];
        exists[val] = curr;
        if (head == nullptr) head = curr;
        string s = *itrNode;
        regex patternNumber("\\d+");
        sregex_token_iterator itrNeighbor(s.begin(), s.end(), patternNumber);
        for (; itrNeighbor != sregex_token_iterator(); itrNeighbor++) {
            string neighbor = *itrNeighbor;
            int n_val = stoi(neighbor);
            Node *node = (exists.find(n_val) == exists.end()) ? new Node(n_val) : node = exists[n_val];
            exists[n_val] = node;
            curr->neighbors.emplace_back(node);
        }
    }

    cout << input << ": input" << endl;
    cout << input << ": expected" << endl;
    Node *res = soln.cloneGraph(head);
    printGraph(res, true);
    return 0;
}