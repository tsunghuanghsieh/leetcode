#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    vector<int> apples, days;
    ifstream fin(argv[1]);
    if (!fin.is_open()) {
        cout << "Failed to open " << argv[1] << endl;
        return 1;
    }

    regex patternNumber("\\d+");
    string iApples, iDays;
    int expected;
    fin >> iApples >> iDays >> expected;
    sregex_token_iterator itr_apples(iApples.begin(), iApples.end(), patternNumber);
    sregex_token_iterator itr_days(iDays.begin(), iDays.end(), patternNumber);
    for (; itr_apples != sregex_token_iterator(); itr_apples++) {
        apples.emplace_back(atoi((*itr_apples).str().c_str()));
    }
    for (; itr_days != sregex_token_iterator(); itr_days++) {
        days.emplace_back(atoi((*itr_days).str().c_str()));
    }
    if (apples.size() != days.size()) {
        cout << "Apples and days should have the same length." << endl;
        return 1;
    }

    cout << iApples << ": apples" << endl;
    cout << iDays << ": days" << endl;
    cout << expected << ": expected" << endl;
    cout << s.eatenApples(apples, days) << ": actual" << endl;
    return 0;
}