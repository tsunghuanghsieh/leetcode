#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution s;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    int n;
    string line, expected;
    fin >> n >> line >> expected;

    vector<vector<int>> dislikes;
    regex patternPairNumbers(R"((\d+),(\d+))");
    sregex_iterator itr(line.begin(), line.end(), patternPairNumbers);
    for (; itr != sregex_iterator(); itr++) {
        dislikes.emplace_back(vector<int>({stoi((*itr)[1]), stoi((*itr)[2])}));
    }

    cout << n << ": n" << endl;
    cout << line << ": dislikes" << endl;
    cout << expected << ": expected" << endl;
    cout << s.possibleBipartition(n, dislikes) << ": actual" << endl;
    return 0;
}