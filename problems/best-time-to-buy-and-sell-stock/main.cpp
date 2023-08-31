#include <fstream>
#include <iostream>
#include <regex>
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
    Solution s;
    ifstream fin;
    fin.open(argv[1]);

    vector<int> prices = readToIntVector(fin);
    cout << s.maxProfit(prices) << endl;
    return 0;
}