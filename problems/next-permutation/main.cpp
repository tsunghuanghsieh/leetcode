#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<int> nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    regex digitPattern("\\d+");
    vector<int> nums;
    string line;
    ifstream fin;

    fin.open(argv[1]);
    getline(fin, line);
    cout << line << " : input " << endl;
    for (sregex_token_iterator itr(line.begin(), line.end(), digitPattern); itr != sregex_token_iterator(); itr++) {
        nums.push_back(atoi((*itr).str().c_str()));
    }

    // Get expected result
    getline(fin, line);
    cout << line << " : expected" << endl;

    soln.nextPermutation(nums);
    printResult(nums);

    return 0;
}