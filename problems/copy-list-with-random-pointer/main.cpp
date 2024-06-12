#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>

using namespace std;

#include "Solution.cpp"


void printResult(Node *head) {
    Node *curr = head;
    vector<int> values;
    map<Node*, int> addresses;
    int i = 0;
    while (curr) {
        values.emplace_back(curr->val);
        addresses[curr] = i++;
        curr = curr->next;
    }
    curr = head;
    i = 0;
    cout << "[";
    while (curr) {
        cout << "[" << values[i++] << "," << ((curr->random) ? to_string(addresses[curr->random]) : "null") << "]";
        curr = curr->next;
        if (curr) cout << ",";
    }
    cout << "]: actual" << endl;
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
    regex patternRandomNode("(-?\\d+),(\\d+|null)");
    sregex_iterator itr(input.begin(), input.end(), patternRandomNode);
    Node *head = nullptr, *curr = nullptr;
    vector<int> random_idx(distance(itr, sregex_iterator()), -1);
    vector<unsigned long> addresses(distance(itr, sregex_iterator()), 0);
    for (int i = 0; itr != sregex_iterator(); i++, itr++) {
        string s((*itr)[1]);
        Node *node = new Node(stoi(s));
        if (!head) {
            head = curr = node;
        }
        else if (head) {
            curr->next = node;
            curr = curr->next;
        }
        addresses[i] = (unsigned long) curr;
        random_idx[i] = ((*itr)[2] == "null") ? -1 : stoi((*itr)[2]);
    }
    for (int i = 0; i < random_idx.size(); i++) {
        if (random_idx[i] == -1) continue;
        ((Node *)addresses[i])->random = (Node *) addresses[random_idx[i]];
    }

    cout << input << ": input" << endl;
    cout << input << ": expected" << endl;
    printResult(soln.copyRandomList(head));
    return 0;
}