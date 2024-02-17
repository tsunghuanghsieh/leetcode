#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }

    string line;
    regex patternStr("\\w+");
    getline(fin, line);
    cout << line << endl;
    sregex_token_iterator itr_str(line.begin(), line.end(), patternStr);
    if (*itr_str != "Solution") {
        cout << "ERROR: " << *itr_str << " is not the expected class name." << endl;
        exit(1);
    }
    int cntCalls = 0;
    while (++itr_str != sregex_token_iterator()) {
        if (*itr_str != "pickIndex") {
            cout << "ERROR: " << *itr_str << " is not the expected class function name." << endl;
            exit(1);
        }
        cntCalls++;
    }

    regex pattern2ndLine("\\[\\[\\[\\d+(,\\d+)*\\]\\](,\\[\\])*\\]");
    getline(fin, line);
    cout << line << endl;
    if (!regex_match(line, pattern2ndLine)) {
        cout << "ERROR: " << line << " contain incorrect format." << endl;
        exit(1);
    }
    vector<int> w;
    regex patternNum("\\d+");
    sregex_token_iterator itr_num(line.begin(), line.end(), patternNum);
    for (; itr_num != sregex_token_iterator(); itr_num++) {
        w.emplace_back(atoi((*itr_num).str().c_str()));
    }
    int cntEmpty = 0;
    regex patternEmpty("\\[\\]");
    sregex_token_iterator itr_empty(line.begin(), line.end(), patternEmpty);
    for (; itr_empty != sregex_token_iterator(); itr_empty++) cntEmpty++;
    if (cntEmpty != cntCalls) {
        cout << "ERROR: count of function calls " << cntCalls << " does not match count of [] " << cntEmpty << endl;
        exit(1);
    }

    Solution soln(w);
    cout << "[null,";
    for (int i = 0; i < cntCalls; i++) {
        cout << soln.pickIndex();
        if (i + 1 != cntCalls) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}