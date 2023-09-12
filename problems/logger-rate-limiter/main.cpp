#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "Logger.cpp"

using namespace std;

pair<vector<string>, vector<string>> parseInput(ifstream& fin) {
    string line;
    vector<string> commands;
    vector<string> logs;
    sregex_token_iterator end;

    std::getline(fin, line);
    regex patternCmd("\\w+");
    for (sregex_token_iterator itr(line.begin(), line.end(), patternCmd); itr != end; itr++) {
        commands.emplace_back(*itr);
    }
    std::getline(fin, line);
    // Looks for [] or [11,"message"]
    regex patternLogs("\\[(\\d+,\"\\w+\")?\\]");
    for (sregex_token_iterator itr(line.begin(), line.end(), patternLogs); itr != end; itr++) {
        logs.emplace_back(*itr);
    }

    return pair<vector<string>, vector<string>>(commands, logs);
}

int main(int argc, char **argv) {
    Logger logger;
    ifstream fin;
    fin.open(argv[1]);
    pair<vector<string>, vector<string>> pairCmdLog = parseInput(fin);
    if (pairCmdLog.first.size() != pairCmdLog.second.size()) {
        cout << "length of methods should be the same as length of params" << endl;
        return -1;
    }
    if (pairCmdLog.first[0] != logger.ClassName()) {
        cout << "The first input method name should be the Constructor name." << endl;
        return -1;
    }
    for (int i = 1; i < pairCmdLog.first.size(); i++) {
        if (pairCmdLog.first[i] == "shouldPrintMessage") {
            cout << pairCmdLog.second[i] << " ";
            sregex_token_iterator end;
            regex patternLogs("\\w+");
            for (sregex_token_iterator itr(pairCmdLog.second[i].begin(), pairCmdLog.second[i].end(), patternLogs); itr != end; itr++) {
                cout << logger.shouldPrintMessage(stoi(*itr), *++itr) << endl;
            }
        }
        else {
            cout << "Unsupported function " << pairCmdLog.second[i] << endl;
        }
    }
    return 0;
}