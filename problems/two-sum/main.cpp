#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main(int argc, char **argv) {
    int target;
    string line;
    ifstream fin;
    fin.open(argv[1]);
    vector<int> result;

    while (!fin.eof()) {
        Solution soln;
        vector<int> nums;
        std::getline(fin, line);
        // cout << "line is " << line << endl;
        stringstream input(line);
        if (!line.size()) continue;
        string tmp;
        // cout << "line is " << line << endl;
        while (std::getline(input, tmp, ',')) {
            // cout << "tmp " << tmp << endl;
            // cout << "input " << std::regex_replace(tmp, std::regex("(^\\s+|\\s+$)"), "") << endl;
            nums.emplace_back(stoi(std::regex_replace(tmp, std::regex("(^\\s+|\\s+$)"), "")));
        }
        fin >> target;
        // cout << "target " << target << endl;
        result = soln.twoSum(nums, target);
        cout << "result " << result[0] << " " << result[1] << endl;
        // read blank line
        // cout << "reading blank line" << endl;
        std::getline(fin, line);
        std::getline(fin, line);
        // cout << "line is " << line << endl;
        cout << endl << endl;
    }
    return 0;
}