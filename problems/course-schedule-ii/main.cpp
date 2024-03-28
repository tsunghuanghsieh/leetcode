#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution s;
    int numCourses, course, prereq;
    vector<vector<int>> prerequisites;
    string line, expected;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    fin >> numCourses >> line >> expected;
    regex patternCourses("\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternCourses);
    for (; itr != sregex_token_iterator(); itr++) {
        prerequisites.push_back({atoi((*itr++).str().c_str()), atoi((*itr).str().c_str())});
    }

    cout << numCourses << ": courses" << endl;
    cout << line << ": course prerequisites" << endl;
    cout << expected << ": expected" << endl;
    vector<int> order = s.findOrder(numCourses, prerequisites);
    cout << "[";
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i + 1 != order.size()) cout << ",";
    }
    cout << "]: actual" << endl;
    return 0;
}