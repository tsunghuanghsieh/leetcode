#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    Solution s;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line, expected;
    fin >> line >> expected;

    vector<vector<int>> intervals;
    regex patternPairNumbers(R"((\d+),(\d+))");
    sregex_iterator itr(line.begin(), line.end(), patternPairNumbers);
    for (; itr != sregex_iterator(); itr++) {
        intervals.emplace_back(vector<int>({stoi((*itr)[1]), stoi((*itr)[2])}));
    }

    cout << line << ": intervals" << endl;
    cout << expected << ": expected" << endl;
    cout << s.minMeetingRooms(intervals) << ": actual" << endl;
    return 0;
}