#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

static vector<string> mfuns = { "AllOne", "inc", "dec", "getMaxKey", "getMinKey" };

int getOpVal(string command) {
    vector<string>::iterator itr = find(mfuns.begin(), mfuns.end(), command);
    return (itr != mfuns.end()) ? itr - mfuns.begin() : -1;
}

int main(int argc, char **argv) {
    AllOne allOne;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string ops, values, expected;
    fin >> ops >> values >> expected;
    cout << expected << ": expected" << endl;

    regex patternCmd("\\w+");
    regex patternArgv("(\\[\\]|\\w+)");
    sregex_token_iterator itr_cmd(ops.begin(), ops.end(), patternCmd);
    sregex_token_iterator itr_value(values.begin(), values.end(), patternArgv);
    vector<string> commands, keys;
    for (int i = 0; itr_cmd != sregex_token_iterator() && itr_value != sregex_token_iterator();
        i++, itr_cmd++, itr_value++) {
        if (i == 0 && *itr_cmd != allOne.ClassName()) {
            cout << "ERROR: " << argv[1] << " contains incorrect class name, " << *itr_cmd << "." << endl;
            exit(1);
        }
        if (getOpVal(*itr_cmd) < 0) {
            cout << "Error: Unknown command " << *itr_cmd << endl;
            exit(1);
        }
        commands.emplace_back(*itr_cmd);
        keys.emplace_back(*itr_value);
    }
    if (commands.size() != keys.size()) {
        cout << "Error: inputs have different lengths." << endl;
        exit(1);
    }

    cout << "[null,";
    for (int i = 1; i < commands.size(); i++) {
        switch (getOpVal(commands[i]))
        {
        case 1:
            allOne.inc(keys[i]);
            cout << "null";
            break;
        case 2:
            allOne.dec(keys[i]);
            cout << "null";
            break;
        case 3:
            cout << "\"" << allOne.getMaxKey() << "\"";
            break;
        case 4:
            cout << "\"" << allOne.getMinKey() << "\"";
            break;
        default:
            cout << "Unknown command " << commands[i] << endl;
            break;
        }
        if (i + 1 < commands.size()) cout << ',';
    }
    cout << "]: actual" << endl;

    return 0;
}
