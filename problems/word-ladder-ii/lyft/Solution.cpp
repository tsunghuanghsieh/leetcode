#include <iostream>
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
        unordered_set<string> currLevel({beginWord}), uwordList(wordList.begin(), wordList.end());
        int currNeighborCount = currLevel.size();

        if (uwordList.count(endWord) == 0) return vector<vector<string>>();

        while (!currLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            // remove all nodes in current level from wordList
            for (string s : currLevel) {
                uwordList.erase(s);
            }
            for (string currWord : currLevel) {
                string temp(currWord);
                // Comparing all permutations of currWord against uwordList, according to LC Editorial,
                // is O(25*k*k+1) or O(k^2) where k is string.size(), instead of explicitly doing
                // string comparison which is O(nk) where n is wordList.size() and k is string.size().
                for (int i = 0; i < currWord.size(); i++) {
                    char ch = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == ch) continue;
                        temp[i] = c;
                        if (uwordList.count(temp) != 0) {
                            if (endWord.compare(temp) == 0) found = true;
                            nextLevel.insert(temp);
                            directedGraph[currWord].insert(temp);
                        }
                    }
                    temp[i] = ch;
                }
            }
            swap(currLevel, nextLevel);
        }

        vector<vector<string>> ladders;
        if (found) {
            cout << "constructing " << directedGraph.size() << endl;;
            cout << "beginWord " << beginWord << " endWord " << endWord << endl;
            constructPaths(beginWord, endWord, {beginWord}, ladders);
        }
        return ladders;
    }
private:
    unordered_map<string, unordered_set<string>> directedGraph;

    // DFS (recursive) to construct the paths to the end word
    void constructPaths(string parent, string endWord, vector<string> ladder, vector<vector<string>>& ladders) {
        if (parent == endWord) {
            ladders.push_back(ladder);
            return;
        }

        const auto itrChildren = directedGraph.find(parent);
        // some new words may not be added to the next level in the directed graph when end word is encountered
        if (itrChildren == directedGraph.end()) return;
        for (string child : itrChildren->second) {
            ladder.push_back(child);
            constructPaths(child, endWord, ladder, ladders);
            ladder.pop_back();
        }
    }
};
