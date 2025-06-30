#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string linePoints, lineLoc;
    int angle, expected;
    fin >> linePoints >> angle >> lineLoc >> expected;

    vector<vector<int>> points;
    regex patternPoint("\\[\\d+,\\d+\\]");
    regex patternNumber("\\d+");
    sregex_token_iterator itrPt(linePoints.begin(), linePoints.end(), patternPoint);
    for (; itrPt != sregex_token_iterator(); itrPt++) {
        vector<int> coord;
        string row((*itrPt).str());
        sregex_token_iterator itrNum(row.begin(), row.end(), patternNumber);
        for (; itrNum != sregex_token_iterator(); itrNum++) {
            coord.emplace_back(stoi(*itrNum));
        }
        points.emplace_back(coord);
    }
    vector<int> location;
    sregex_token_iterator itrLoc(lineLoc.begin(), lineLoc.end(), patternNumber);
    for (; itrLoc != sregex_token_iterator(); itrLoc++) {
        location.emplace_back(stoi(*itrLoc));
    }

    cout << linePoints << ": points" << endl;
    cout << angle << ": angle" << endl;
    cout << lineLoc << ": location" << endl;
    cout << expected << ": expected" << endl;
    cout << soln.visiblePoints(points, angle, location) << ": actual" << endl;
    return 0;
}