#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    regex digitPattern("-?\\d+");
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
    int target;
    fin >> target;
    cout << "target: " << target << endl;
    cout << "Result: " << soln.search(nums, target) << endl;

    return 0;
}