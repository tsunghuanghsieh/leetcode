#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(const vector<double>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << std::fixed << setprecision(5) << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char** argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    int k;
    fin >> line >> k >> expected;

    vector<int> nums;
    regex patternNumber(R"(-?\d+)");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.emplace_back(stoi(*itr));
    }

    cout << line << ": nums" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;
    printResult(soln.medianSlidingWindow(nums, k));

    return 0;
}
