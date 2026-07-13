#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

static vector<string> mfuns = { "MyCircularQueue", "Front", "Rear", "enQueue", "deQueue", "isEmpty", "isFull" };

int getOpVal(string command) {
    vector<string>::iterator itr = find(mfuns.begin(), mfuns.end(), command);
    return (itr != mfuns.end()) ? itr - mfuns.begin() : -1;
}

int main(int argc, char **argv) {
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    string ops, ops_values, expected;
    fin >> ops >> ops_values >> expected;

    regex patternCmd("\\w+");
    regex patternArgv("(\\[\\]|\\d+)");
    sregex_token_iterator itr_cmd(ops.begin(), ops.end(), patternCmd);
    sregex_token_iterator itr_value(ops_values.begin(), ops_values.end(), patternArgv);
    vector<string> commands, values;
    for (int i = 0; itr_cmd != sregex_token_iterator() && itr_value != sregex_token_iterator();
        i++, itr_cmd++, itr_value++) {
        if (getOpVal(*itr_cmd) < 0) {
            cout << "Error: Unknown command " << *itr_cmd << endl;
            exit(1);
        }
        commands.emplace_back(*itr_cmd);
        values.emplace_back(*itr_value);
    }
    if (commands.size() != values.size()) {
        cout << "Error: inputs have different lengths." << endl;
        exit(1);
    }

    cout << values[0] << endl;
    MyCircularQueue q(stoi(values[0]));
    if (commands[0] != q.ClassName()) {
        cout << "ERROR: " << argv[1] << " contains incorrect class name, " << commands[0] << "." << endl;
        exit(1);
    }

    cout << ops << ": input" << endl;
    cout << ops_values << ": input" << endl;
    cout << expected << ": expected" << endl;

    cout << std::boolalpha << "[null,";
    for (int i = 1; i < commands.size(); i++) {
        switch (getOpVal(commands[i]))
        {
        case 1:
            cout << q.Front();
            break;
        case 2:
            cout << q.Rear();
            break;
        case 3:
            cout << q.enQueue(stoi(values[i]));
            break;
        case 4:
            cout << q.deQueue();
            break;
        case 5:
            cout << q.isEmpty();
            break;
        case 6:
            cout << q.isFull();
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
