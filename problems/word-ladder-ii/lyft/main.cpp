#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Solution.cpp"

int main(int argc, char** argv) {
    int cntInput = 0, cntWordList = 0;
    vector<pair<string, string>> inputs;
    set<string> wordList;
    string beginWord, endWord;
    Solution s;
    ifstream fin(argv[1]);

    fin >> cntInput; // read # of pairs
    for (int i = 0; i < cntInput; i++) {
        // read input pairs
        fin >> beginWord >> endWord;
        inputs.push_back(make_pair(beginWord, endWord));
    }
    fin >> cntWordList; // read # of words in dictionary
    for (int i = 0; i < cntWordList; i++) {
        string word;
        fin >> word;
        wordList.insert(word);
    }

    for (int i = 0; i < inputs.size(); i++) {
        vector<vector<string>> results = s.bfs(inputs[i].first, inputs[i].second, wordList);
        cout << results.size() << endl;
        for (vector<string> path : results) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i + 1 != path.size()) cout << ",";
            }
            cout << endl;
        }
    }

    return 0;
}
