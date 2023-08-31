#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

vector<int> readToIntVector(ifstream& fin) {
    string line, value;
    vector<int> nums;

    std::getline(fin, line);
    stringstream ss(line);
    while (std::getline(ss, value, ',')) {
        nums.emplace_back(stoi(std::regex_replace(value, std::regex("(^\\s+|\\s+$|\\[|\\]|\")"), "")));
    }
    // debug
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << "nums[" << i << "] " << nums[i] <<  endl;
    // }
    return nums;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    vector<int> nums = readToIntVector(fin);
    int target;
    fin >> target;
    cout << "target " << target << endl;
    int result = soln.searchInsert(nums, target);
    cout << result << endl;
    return 0;
}