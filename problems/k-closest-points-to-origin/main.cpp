#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i < res.size() - 1) cout << ",";
    }
    cout << "] : actual" << endl;
}

int main(int argc, char **argv)
{
    Solution soln;

    ifstream fin;
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line, expected;
    int k;
    fin >> line >> k >> expected;
    cout << line << ": input" << endl;
    cout << k << ": k" << endl;
    cout << expected << ": expected" << endl;

    regex patternNumber("-?\\d+");
    vector<vector<int>> points;
    sregex_token_iterator itr(line.begin(), line.end(), patternNumber);
    for (; itr != sregex_token_iterator();)
    {
        vector<int> point;
        point.push_back(stoi((*itr++).str()));
        point.push_back(stoi((*itr++).str()));
        points.push_back(point);
    }

    const vector<vector<int>> res(soln.kClosest(points, k));
    printResult(res);
    return 0;
}