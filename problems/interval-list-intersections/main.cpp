#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void parseList(string line, vector<vector<int>> &list) {
    regex patternNumber("\\d+");
    sregex_token_iterator itr1(line.begin(), line.end(), patternNumber);
    for (; itr1 != sregex_token_iterator(); itr1++) {
        vector<int> interval;
        interval.push_back(stoi((*itr1).str()));
        itr1++;
        interval.push_back(stoi((*itr1).str()));
        list.push_back(interval);
    }
}

void printList(vector<vector<int>> list) {
    cout << "[";
    for (int i = 0; i < list.size(); i++) {
        cout << "[" << list[i][0] << "," << list[i][1] << "]";
        if (i + 1 < list.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string s1, s2, expected;
    fin >> s1 >> s2 >> expected;
    cout << s1 << ": firstList" << endl;
    cout << s2 << ": secondList" << endl;
    cout << expected << ": expected" << endl;

    vector<vector<int>> firstList, secondList, actualList;
    parseList(s1, firstList);
    parseList(s2, secondList);
    actualList = soln.intervalIntersection(firstList, secondList);
    printList(actualList);
    return 0;
}