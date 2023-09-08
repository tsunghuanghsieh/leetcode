#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "Solution.cpp"


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
    vector<int> arr = readToIntVector(fin);

    vector<int> result = soln.sortByBits(arr);
    for (int i = 0; i < result.size(); i++) {
        cout << "result[" << i << "] " << result[i] <<  endl;
    }
    return 0;
}