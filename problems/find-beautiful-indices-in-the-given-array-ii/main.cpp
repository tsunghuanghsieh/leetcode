#include <fstream>
#include <iostream>
#include <math.h>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution1.cpp"

void printResult(vector<int> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
}

int main(int argc, char **argv) {
    Solution soln;
    Solution1 soln1;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string s, a, b, expected;
    int k;
    fin >> s >> a >> b >> k >> expected;

    if (k > s.size()) {
        cout << "ERROR: value of k " << k << " must be <= to size of s " << s.size() << "." << endl;
        exit(1);
    }

    vector<int> exp_res;
    regex patternNum("\\d+");
    sregex_token_iterator itr(expected.begin(), expected.end(), patternNum);
    for (; itr != sregex_token_iterator(); itr++) {
        exp_res.emplace_back(stoi((*itr)));
    }

    cout << ((s.size() > 80) ? (s.substr(0, 40) + "...(" +  to_string(s.size()) + ")") : s) << ": s" << endl;
    cout << ((a.size() > 80) ? (a.substr(0, 40) + "...(" +  to_string(a.size()) + ")") : a) << ": a" << endl;
    cout << ((b.size() > 80) ? (b.substr(0, 40) + "...(" +  to_string(b.size()) + ")") : b) << ": b" << endl;
    cout << k << ": k" << endl;
    vector<int> act_res = soln.beautifulIndices(s, a, b, k);
    vector<int> act_res1 = soln1.beautifulIndices(s, a, b, k);
    if (exp_res.size() <= 20) {
        cout << expected << ": expected" << endl;
        printResult(act_res);
        cout << "]: actual" << endl;
        printResult(act_res1);
        cout << "]: actual 1" << endl;
    }
    else {
        bool diff = false;
        if (exp_res.size() != act_res.size()) {
            cout << exp_res.size() << ": expected count " << endl << act_res.size() << ": actual count " << endl;
            diff = true;
        }

        int i = 0;
        for (; i < exp_res.size() && i < act_res.size(); i++) {
            if (exp_res[i] != act_res[i]) {
                diff = true;
                cout << "i: " << i << " exp_res " << exp_res[i] << " act_res " << act_res[i] << endl;
            }
        }
        while (i < exp_res.size()) cout << "i: " << i << " exp_res " << exp_res[i++] << endl;
        while (i < act_res.size()) cout << "i: " << i << " act_res " << act_res[i++] << endl;

        if (!diff) cout << "actual result and expected result are identical." << endl;

        bool diff1 = false;
        if (exp_res.size() != act_res1.size()) {
            cout << exp_res.size() << ": expected count " << endl << act_res1.size() << ": actual 1 count " << endl;
            diff1 = true;
        }
        i = 0;
        for (; i < exp_res.size() && i < act_res1.size(); i++) {
            if (exp_res[i] != act_res1[i]) {
                diff1 = true;
                cout << "i: " << i << " exp_res " << exp_res[i] << " act_res1 " << act_res1[i] << endl;
            }
        }
        while (i < exp_res.size()) cout << "i: " << i << " exp_res " << exp_res[i++] << endl;
        while (i < act_res1.size()) cout << "i: " << i << " act_res1 " << act_res1[i++] << endl;

        if (!diff1) cout << "actual 1 result and expected result are identical." << endl;
    }
    return 0;
}
