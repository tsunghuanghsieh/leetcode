#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

ListNode* readToListNode(ifstream& fin) {
    string line, value;
    ListNode *head = NULL, *last = NULL;

    std::getline(fin, line);
    stringstream ss(line);
    while (std::getline(ss, value, ',')) {
        ListNode *node = new ListNode();
        node->val = stoi(std::regex_replace(value, std::regex("(^\\s+|\\s+$|\\[|\\]|\")"), ""));
        if (!head) head = last = node;
        if (last != node) {
            last->next = node;
            last = node;
        }
    }
    // debug
    // for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next) {
    //     cout << "ptr->val " << ptr->val <<  endl;
    // }
    return head;
}

int main (int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    ifstream fin;
    fin.open(argv[1]);
    ListNode *head = readToListNode(fin);

    cout << "soln.isPalindrome " << soln.isPalindrome(head) << endl;
    cout << "soln2.isPalindrome " << soln2.isPalindrome(head) << endl;
    return 0;
}