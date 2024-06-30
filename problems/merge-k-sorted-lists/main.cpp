#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"


void printList(ListNode *head, bool res = false) {
    ListNode *temp = head;
    cout << "[";
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << ",";
        temp = temp->next;
    }
    cout << "]";
    if (res) cout << ": actual" << endl;
}

void printLists(vector<ListNode*> lists) {
    cout << "[";
    for (int i = 0; i < lists.size(); i++) {
        printList(lists[i]);
        if (i + 1 < lists.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string line, expected;
    fin >> line >> expected;

    vector<ListNode*> lists;
    regex PatternNumberList("\\[((-?\\d+)?|(-?\\d)+(,-?\\d+)*)\\]");
    regex PatternNumber("-?\\d+");
    sregex_iterator itr(line.begin(), line.end(), PatternNumberList);
    for (; itr != sregex_iterator(); itr++) {
        string s = (*itr)[1];
        sregex_token_iterator itr_num(s.begin(), s.end(), PatternNumber);
        ListNode *head = nullptr, *temp;
        for (; itr_num != sregex_token_iterator(); itr_num++) {
            ListNode *node = new ListNode(stoi(*itr_num));
            if (!head) head = temp = node;
            else {
                temp->next = node;
                temp = node;
            }
        }
        lists.emplace_back(head);
    }
    cout << line << ": list" << endl;
    cout << expected << ": expected" << endl;
    printList(soln.mergeKLists(lists), true);
    return 0;
}