#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char **argv)
{
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }
    string commands, arguments, expected;
    fin >> commands >> arguments >> expected;

    cout << commands << ": commands" << endl;
    cout << arguments << ": data" << endl;
    cout << expected << ": possible result" << endl;

    regex patternCmd("\\w+");
    vector<string> cmds;
    sregex_token_iterator itr_cmd(commands.begin(), commands.end(), patternCmd);
    for (int i = 0; itr_cmd != sregex_token_iterator(); i++, itr_cmd++) {
        if (i == 0 && (*itr_cmd).str() != Solution::ClassName) {
            cout << "The first command value should be the class name." << endl;
            return -1;
        }
        else if (i > 0 && (*itr_cmd).str() != Solution::FuncName) {
            cout << (*itr_cmd).str() << " unsupported method." << endl;
            return -1;
        }
        cmds.emplace_back((*itr_cmd).str());
    }

    regex patternArguments("\\[\\d+(,\\d+)*\\]");
    regex patternNumber("\\d+");
    vector<vector<int>> cmdArgvs;
    sregex_token_iterator itr_argvs(arguments.begin(), arguments.end(), patternArguments);
    for (; itr_argvs != sregex_token_iterator(); itr_argvs++) {
        string s = (*itr_argvs).str();
        sregex_token_iterator itr_s(s.begin(), s.end(), patternNumber);
        vector<int> data;
        for (; itr_s != sregex_token_iterator(); itr_s++) {
            data.emplace_back(stoi((*itr_s).str()));
        }
        cmdArgvs.emplace_back(data);
    }

    if (cmds.size() != cmdArgvs.size()) {
        cout << "length of commands should be the same as length of arguments" << endl;
        return -1;
    }

    Solution soln(cmdArgvs[0]);
    cout << "[null,";
    for (int i = 1; i < cmdArgvs.size(); i++) {
        cout << soln.pick(cmdArgvs[i][0]);
        cout << endl;
        if (i != cmdArgvs.size() - 1) cout << ",";
    }
    cout << "]: actual" << endl;
    return 0;
}
