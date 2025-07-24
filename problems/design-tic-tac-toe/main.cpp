#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(vector<int> res) {
    cout << "[null,";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 < res.size()) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string line1, line2, expected;
    fin >> line1 >> line2 >> expected;

    // no need to process line1

    int n;
    vector<vector<int>> moves;
    regex patternMove(R"(\[(\d+)\]|(\d+),(\d+),(\d+))");
    sregex_iterator itr_mv(line2.begin(), line2.end(), patternMove);
    for (; itr_mv != sregex_iterator(); itr_mv++) {
        if ((*itr_mv)[1].str().size()) {
            n = stoi((*itr_mv)[1].str());
        }
        else {
            vector<int> move({stoi((*itr_mv)[2].str()), stoi((*itr_mv)[3].str()), stoi((*itr_mv)[4].str())});
            moves.emplace_back(move);
        }
    }

    TicTacToe t3(n);
    vector<int> res;
    for (int i = 0; i < moves.size(); i++) {
        res.emplace_back(t3.move(moves[i][0], moves[i][1], moves[i][2]));
    }

    cout << line2 << ": moves" << endl;
    cout << expected << ": expected" << endl;
    printResult(res);
    return 0;
}