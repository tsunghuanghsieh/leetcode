#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution s;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line1, line2;
    double expected;
    vector<int> num1, num2;
    fin >> line1 >> line2 >> expected;
    regex patternNumber("(-)?\\d+");
    sregex_token_iterator itr_1(line1.begin(), line1.end(), patternNumber);
    for (; itr_1 != sregex_token_iterator(); itr_1++) {
        num1.push_back(atoi((*itr_1).str().c_str()));
    }
    sregex_token_iterator itr_2(line2.begin(), line2.end(), patternNumber);
    for (; itr_2 != sregex_token_iterator(); itr_2++) {
        num2.push_back(atoi((*itr_2).str().c_str()));
    }
    cout << line1 << ": num1" << endl;
    cout << line2 << ": num2" << endl;
    cout << setprecision(5) << std::fixed << expected << ": expected" << endl;
    cout << s.findMedianSortedArrays(num1, num2) << ": actual" << endl;
    return 0;
}