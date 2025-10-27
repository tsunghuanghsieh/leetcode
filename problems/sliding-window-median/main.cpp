#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution1.cpp"

string formatResult(const vector<double>& result) {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < result.size(); i++) {
        ss << std::fixed << setprecision(5) << result[i];
        if (i < result.size() - 1) ss << ",";
    }
    ss << "]";
    return ss.str();
}

void printResult(const vector<double>& exp, const string expected,
    const vector<double>& act, const string actual, int num=0) {
    cout << ((exp.size() > 10) ? (expected.substr(0, 40) + "...(" +  to_string(exp.size()) + ")") :
             expected) << ": expected" << endl;
    cout << ((act.size() > 20) ? (actual.substr(0, 40) + "...(" +  to_string(act.size()) + ")") :
             actual) << ": actual " << num << endl;
    if (actual == expected) cout << "actual result and expected result are identical." << endl;
    else {
        if (act.size() != exp.size()) {
            cout << "count expected: " << exp.size() << endl;
            cout << "count actual  : " << act.size() << endl;
        }
        else {
            for (int i = 0; i < act.size(); i++) {
                if (act != exp)
                    cout << "count " << i << ": expected " << exp[i] << " actual " << act[i] << endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    Solution soln;
    Solution1 soln1;
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

    vector<double> exp;
    regex patternResult(R"(-?\d+.\d+)");
    sregex_token_iterator itr_exp(expected.begin(), expected.end(), patternResult);
    for (; itr_exp != sregex_token_iterator(); itr_exp++) {
        exp.emplace_back(stod(*itr_exp));
    }

    cout << ((nums.size() > 10) ? (line.substr(0, 40) + "...(" +  to_string(nums.size()) + ")") :
             line) << ": nums" << endl;
    cout << k << ": k" << endl;
    vector<double> act = soln.medianSlidingWindow(nums, k);
    string actual = formatResult(act);
    printResult(exp, expected, act, actual);
    vector<double> act1 = soln.medianSlidingWindow(nums, k);
    string actual1 = formatResult(act1);
    printResult(exp, expected, act1, actual1, 1);
    return 0;
}
