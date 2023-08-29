#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

vector<string> readToStringVector(ifstream& fin) {
    string line, value;
    vector<string> strs;

    std::getline(fin, line);
    stringstream ss(line);
    while (std::getline(ss, value, ',')) {
        strs.emplace_back(std::regex_replace(value, std::regex("(^\\s+|\\s+$|\\[|\\]|\")"), ""));
    }
    // debug
    // for (int i = 0; i < strs.size(); i++) {
    //     cout << strs[i] << " " << strs[i].size() << endl;
    // }
    return strs;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    vector<string> strs = readToStringVector(fin);
    string result = soln.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}