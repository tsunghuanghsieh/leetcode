#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results;
        queue<string> currNeighbors({beginWord});
        set<string> known({beginWord}), uniqueCurrNeighbors;
        int currNeighborsCount = currNeighbors.size();

        // BFS to find endWord
        // iteratively finding adjacent neighbors until endWord is found or wordList is exhausted
        while (currNeighborsCount != 0) {
            string currWord = currNeighbors.front();
            currNeighbors.pop();
            currNeighborsCount--;

            vector<string> newNeighbors = findNeighbors(currWord, wordList, known);

            for (string neighbor : newNeighbors) {
                uniqueCurrNeighbors.insert(neighbor);
                inverseGraph[neighbor].emplace_back(currWord);
            }
            if (currNeighborsCount == 0) {
                if (uniqueCurrNeighbors.count(endWord)) {
                    break;
                }

                for (auto itr = uniqueCurrNeighbors.begin(); itr != uniqueCurrNeighbors.end(); itr++) {
                    currNeighbors.push(*itr);
                    known.insert(*itr);
                }
                currNeighborsCount = currNeighbors.size();
                uniqueCurrNeighbors.clear();
            }
        }

        constructLadder(endWord, beginWord, vector<string>({endWord}), results);
        return results;
    }
private:
    unordered_map<string, vector<string>> inverseGraph;
    void constructLadder(const string& beginWord, const string& endWord, vector<string> ladder, vector<vector<string>>& results) {
        if (beginWord.compare(endWord) == 0) {
            results.emplace_back(ladder);
            return;
        }
        if (inverseGraph.count(beginWord) == 0) return;
        for (string s : inverseGraph[beginWord]) {
            ladder.emplace(ladder.begin(), s);
            constructLadder(s, endWord, ladder, results);
            ladder.erase(ladder.begin());
        }
    }

    vector<string> findNeighbors(string currWord, vector<string>& wordList, set<string>& visited) {
        vector<string> results;
        for (auto itr = wordList.begin(); itr != wordList.end(); itr++) {
            if (visited.count(*itr) > 0) continue;
            int diff = 0;
            for (int i = 0; i < currWord.size(); i++) {
                if ((*itr)[i] != currWord[i]) diff++;
                if (diff > 1) break;
            }
            if (diff == 1) results.emplace_back(*itr);
        }
        return results;
    }
};
