#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> bfs(string beginWord, string endWord, set<string>& wordList) {
        bool found = false;
        vector<vector<string>> result;
        queue<string> que({beginWord});
        unordered_set<string> currLevel({ beginWord }), nextLevel;
        int currNeighborCount = 1;
        vector<string> newNeighbors;
        vector<string> neighborsToDelete;
        unordered_map<string, unordered_set<string>> children;
        // unordered_map<string, vector<string>> children;

        if (wordList.count(endWord) == 0) return result;

        wordList.erase(beginWord);
        while (!que.empty()) {
        // while (!que.empty() && currNeighborCount != 0) {
            string currWord = que.front();
            que.pop();
            currNeighborCount--;
            newNeighbors = findNeighbors(currWord, endWord, que, wordList);
            for (string newNeighbor : newNeighbors) {
                if (newNeighbor == endWord) found = true;
                que.push(newNeighbor);
                // if (!found) que.push(newNeighbor);
                children[currWord].insert(newNeighbor);
                // children[currWord].push_back(newNeighbor);
                neighborsToDelete.push_back(newNeighbor);
            }
            if (currNeighborCount == 0) {
                // delete neighbors when this level is done
                for (string neighbor : neighborsToDelete) {
                    // if (neighbor != endWord) {
                        wordList.erase(neighbor);
                    // }
                }
                currNeighborCount = (!found) ? que.size() : 0;
                // currNeighborCount = que.size();
            }
        }

        // return constructPathsSlow(beginWord, endWord, children);

        vector<string> ladder = { beginWord };
        vector<vector<string>> ladders;
        if (found) {
            cout << "constructing " << children.size() << endl;;
            cout << "beginWord " << beginWord << " endWord " << endWord << endl;
            constructPathsFast(beginWord, endWord, children, ladder, ladders);
        }
        return ladders;
    }

    vector<vector<string>> bfs_vector(string beginWord, string endWord, set<string>& wordList) {
        bool found = false;
        vector<vector<string>> result;
        queue<string> que({beginWord});
        unordered_set<string> currLevel({ beginWord }), nextLevel;
        int currNeighborCount = 1;
        vector<string> newNeighbors;
        vector<string> neighborsToDelete;
        unordered_map<string, vector<string>> children;

        if (wordList.count(endWord) == 0) return result;

        while (!currLevel.empty() && !found) {
            // remove all nodes in current level from wordList
            for (string s : currLevel) {
                wordList.erase(s);
            }
            for (string currWord : currLevel) {
                char chCurrWord[currWord.size() + 1];
                strcpy(chCurrWord, currWord.c_str());
                for (int i = 0; i < currWord.size(); i++) {
                    char ch = chCurrWord[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == ch) continue;
                        chCurrWord[i] = c;
                        if (wordList.count(string(chCurrWord)) != 0) {
                            if (endWord.compare(chCurrWord) == 0) found = true;
                            nextLevel.insert(chCurrWord);
                            children[currWord].push_back(string(chCurrWord));
                        }
                    }
                    chCurrWord[i] = ch;
                }
            }
            swap(currLevel, nextLevel);
            nextLevel.clear();
        }

        return constructPathsSlow_vector(beginWord, endWord, children);
    }
private:
    // Given a word, find all neighboring words in the word list.
    // If the word list (M) is long, comparing word against the entire word list will be O(M).
    // Instead get all permutation of word O(length of word * 26), then do constant O(1) lookup.
    vector<string> findNeighbors(string word, string endWord, queue<string>& que, set<string> wordsList) {
        char me[word.size() + 1];
        strcpy(me, word.c_str());
        vector<string> neighbors;
        for (int i = 0; i < word.size(); i++) {
            char ch = me[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == ch) continue;
                me[i] = c;
                if (wordsList.count(string(me)) != 0) {
                    // que.push(me);
                    neighbors.push_back(me);
                }
            }
            me[i] = ch;
        }
        return neighbors;
    }

    // DFS (recursive) to construct the paths to the end word
    void constructPathsFast(string parent, string endWord, const unordered_map<string, unordered_set<string>>& directedGraph,
    // void constructPathsFast(string parent, string endWord, const unordered_map<string, vector<string>>& directedGraph,
                            vector<string> ladder, vector<vector<string>>& ladders) {
        if (parent == endWord) {
            ladders.push_back(ladder);
            return;
        }

        //
        // TODO: make it non recursive
        //

        const auto itrChildren = directedGraph.find(parent);
        // some new words may not be added to the next level in the directed graph when end word is encountered
        if (itrChildren == directedGraph.end()) return;
        for (string child : itrChildren->second) {
            ladder.push_back(child);
            constructPathsFast(child, endWord, directedGraph, ladder, ladders);
            ladder.pop_back();
        }
        return;
    }

    // DFS (recursive) to construct the paths to the end word
    vector<vector<string>> constructPathsSlow(string parent, string endWord, unordered_map<string, unordered_set<string>> directedGraph) {
        vector<vector<string>> results;
        vector<string> path;

        if (parent == endWord) {
            results.push_back({endWord});
            return results;
        }
        path.push_back(parent);
        for (string child : directedGraph[parent]) {
            vector<vector<string>> temps = constructPathsSlow(child, endWord, directedGraph);
            for (vector<string> temp : temps) {
                vector<string> base = path;
                base.insert(base.end(), temp.begin(), temp.end());
                results.push_back(base);
                // path.insert(path.end(), temp.begin(), temp.end());
                // results.push_back(path);
            }
        }
        return results;
    }

    // DFS (recursive) to construct the paths to the end word
    vector<vector<string>> constructPathsSlow_vector(string parent, string endWord, unordered_map<string, vector<string>> directedGraph) {
        vector<vector<string>> results;
        vector<string> path;

        if (parent == endWord) {
            results.push_back({endWord});
            return results;
        }
        path.push_back(parent);
        for (string child : directedGraph[parent]) {
            vector<vector<string>> temps = constructPathsSlow_vector(child, endWord, directedGraph);
            for (vector<string> temp : temps) {
                // vector<string> base = path;
                // base.insert(base.end(), temp.begin(), temp.end());
                // results.push_back(base);
                path.insert(path.end(), temp.begin(), temp.end());
                results.push_back(path);
            }
        }
        return results;
    }
};

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