#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"
#include "Solution2.cpp"

void printResult(vector<double>& result, string s) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << fixed << setprecision(5) << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]: actual " << s << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    Solution2 soln2;
    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string line_equations, line_values, line_queries, expected;
    fin >> line_equations >> line_values >> line_queries >> expected;

    vector<vector<string>> equacations;
    regex patternEquation(R"(["]([a-z0-9]+)["],["]([a-z0-9]+)["])");
    sregex_iterator itrEqn(line_equations.begin(), line_equations.end(), patternEquation);
    for (; itrEqn != sregex_iterator(); itrEqn++) {
        equacations.emplace_back(vector<string>({(*itrEqn)[1], (*itrEqn)[2]}));
    }

    vector<double> values;
    regex patternDouble(R"(\d+(.\d+)?)");
    sregex_token_iterator itrDbl(line_values.begin(), line_values.end(), patternDouble);
    for (; itrDbl != sregex_token_iterator(); itrDbl++) {
        values.emplace_back(stod(*itrDbl));
    }

    if (equacations.size() != values.size()) {
        cout << "Error: Equation and value length mismatch, equations.size() " << equacations.size() <<
            " values.size() " << values.size() << endl;
        exit(1);
    }

    vector<vector<string>> queries;
    sregex_iterator itrQueries(line_queries.begin(), line_queries.end(), patternEquation);
    for (; itrQueries != sregex_iterator(); itrQueries++) {
        queries.emplace_back(vector<string>({(*itrQueries)[1], (*itrQueries)[2]}));
    }

    if (equacations.size() < 1 || equacations.size() > 20 || values.size() < 1 || values.size() > 20 ||
        queries.size() < 1 || queries.size() > 20) {
        cout << "Error: Input size must be 1 - 20, inclusive." << endl;
        exit(1);
    }

    cout << line_equations << ": equations" << endl;
    cout << line_values << ": values" << endl;
    cout << line_queries << ": queries" << endl;
    cout << expected << ": expected" << endl;
    vector<double> result = soln.calcEquation(equacations, values, queries);
    printResult(result, "soln");
    vector<double> result2 = soln2.calcEquation(equacations, values, queries);
    printResult(result2, "soln 2");
    return 0;
}
