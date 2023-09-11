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

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);

    vector<int> nums = readToIntVector(fin);
    int target;
    fin >> target;
    cout << "target at " << soln.search(nums, target) << endl;
    return 0;
}