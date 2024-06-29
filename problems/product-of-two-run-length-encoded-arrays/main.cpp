#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void parseEncoded(const string& line, vector<vector<int>>& encoded) {
    regex patternEncodedd("(\\d+),(\\d+)");
    sregex_iterator itr(line.begin(), line.end(), patternEncodedd);
    for (; itr != sregex_iterator(); itr++) {
        vector<int> nums({stoi((*itr)[1]), stoi((*itr)[2])});
        encoded.push_back(nums);
    }
}

void printEncoded(const vector<vector<int>> &encoded, bool res = false) {
    cout << "[";
    for (int i = 0; i < encoded.size(); i++) {
        cout << "[" << encoded[i][0] << "," << encoded[i][1] << "]";
        if (i < encoded.size() - 1) cout << ",";
    }
    cout << "]";
    if (res) cout << ": actual";
    cout << endl;
}

void printResult(vector<vector<int>> res) {
    printEncoded(res, true);
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string line1, line2, expected;
    fin >> line1 >> line2 >> expected;
    cout << line1 << ": line1" << endl;
    cout << line2 << ": line2" << endl;
    cout << expected << ": expected" << endl;

    vector<vector<int>> encoded1, encoded2;
    parseEncoded(line1, encoded1);
    parseEncoded(line2, encoded2);
    printResult(soln.findRLEArray(encoded1, encoded2));
    return 0;
}