#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    fin >> line;
    getline(fin, expected);   // eat \n character
    getline(fin, expected);

    vector<int> nums;
    regex patternNumber("-?\\d+");
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator(); itr++) {
        nums.push_back(stoi((*itr).str()));
    }

    cout << line << ": line" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.findPeakElement(nums) << ": actual" << endl;
    return 0;
}
