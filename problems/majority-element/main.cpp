#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Solution.cpp"
#include "Solution2.cpp"

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
    Solution2 soln2;
    ifstream fin;
    fin.open(argv[1]);

    vector<int> nums = readToIntVector(fin);
    cout << "majority is " << soln.majorityElement(nums) << endl;
    return 0;
}