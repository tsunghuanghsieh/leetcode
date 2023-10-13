
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Solution.cpp"

using namespace std;

vector<int> readToIntVector(ifstream& fin) {
    string line, value;
    vector<int> nums;

    std::getline(fin, line);
    cout << line << " : input" << endl;
    regex patternDigits("(-?\\d+)");
    const sregex_token_iterator end;
    for (sregex_token_iterator itr(line.begin(), line.end(), patternDigits); itr != end; itr++) {
        nums.emplace_back(stoi(*itr));
    }
    // debug
    // for (int num : nums) {
    //     cout << num << " ";
    // }
    // cout << endl;
    return nums;
}

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "] : actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    vector<int> heights = readToIntVector(fin);
    string expected;
    fin >> expected;
    cout << expected << " : expected" << endl;
    vector<int> result = soln.findBuildings(heights);
    printResult(result);
    return 0;
}

