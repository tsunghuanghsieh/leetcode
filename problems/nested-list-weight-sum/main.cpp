#include <iostream>
#include <fstream>
#include <regex>
#include <stack>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "NestedInteger.cpp"

const vector<NestedInteger>& constructNestedList(string input) {
    NestedInteger *curr = nullptr;
    stack<NestedInteger*> stk;
    regex patternNumber("(-?\\d+|\\[|\\])");
    sregex_token_iterator itr(input.begin(), input.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        NestedInteger *ni = new NestedInteger();
        if (*itr == '[') {
            if (curr != nullptr) {
                curr->add(*ni);
                stk.push(curr);
            }
            curr = ni;
        }
        else if (*itr == ']') {
            if (!stk.empty()) {
                curr = stk.top();
                stk.pop();
            }
        }
        else {
            ni->setInteger(stoi((*itr).str()));
            curr->add(*ni);
        }
    }
    return curr->getList();
}

void printInput(const vector<NestedInteger> nestedList) {
    cout << "[";
    for (int i = 0; i < nestedList.size(); i++) {
        if (nestedList[i].isInteger()) {
            cout << nestedList[i].getInteger();
            if (i <= nestedList.size() - 2) cout << ",";
        }
        else {
            printInput(nestedList[i].getList());
        }
    }
    cout << "]";
}

int main(int argc, char **argv) {
    Solution s;
    vector<NestedInteger> nestedList;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line;
    int expected;
    fin >> line >> expected;
    nestedList = constructNestedList(line);
    cout << line << ": input" << endl;
    cout << expected << ": expected" << endl;
    cout << s.depthSum(nestedList) << ": actual" << endl;
    return 0;
}