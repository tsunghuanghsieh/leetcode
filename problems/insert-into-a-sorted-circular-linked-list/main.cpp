#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

#include "Solution.cpp"

void printNodes(Node *head) {
    Node *curr = head;
    cout << "[";
    while (curr != nullptr && curr->next != head) {
        cout << curr->val << ",";
        curr = curr->next;
    }
    if (curr != nullptr) cout << curr->val;
    cout << "]";
}

int main(int argc, char **argv) {
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line1, expected;
    int val;
    fin >> line1 >> val >> expected;

    regex patternNumber("-?\\d+");
    Node *head = nullptr, *curr = nullptr;
    sregex_token_iterator itr(line1.begin(), line1.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        Node *node = new Node(stoi((*itr).str()));
        if (head == nullptr) {
            node->next = node;
            head = curr = node;
        } else {
            curr->next = node;
            curr = node;
            node->next = head;
        }
    }

    cout << line1 << ": stickers" << endl;
    cout << val << ": value" << endl;
    cout << expected << ": expected" << endl;
    head = soln.insert(head, val);
    printNodes(head);
    cout << ": actual" << endl;
    return 0;
}