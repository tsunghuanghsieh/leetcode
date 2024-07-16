#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results;
        queue<string> currNeighbors({beginWord});
        unordered_set<string> wordListSet(wordList.begin(), wordList.end()), uniqueNewNeighbors;
        int currNeighborsCount = currNeighbors.size();

        // BFS to find endWord
        // iteratively finding adjacent neighbors until endWord is found or wordList is exhausted
        while (currNeighborsCount != 0) {
            string currWord = currNeighbors.front();
            currNeighbors.pop();
            currNeighborsCount--;

            vector<string> newNeighbors = findNeighbors(currWord, wordListSet);
            for (string neighbor : newNeighbors) {
                uniqueNewNeighbors.insert(neighbor);
                inverseGraph[neighbor].emplace_back(currWord);
            }
            if (currNeighborsCount == 0) {
                if (uniqueNewNeighbors.count(endWord)) break;

                for (auto itr = uniqueNewNeighbors.begin(); itr != uniqueNewNeighbors.end(); itr++) {
                    currNeighbors.push(*itr);
                    wordListSet.erase(*itr);
                }
                currNeighborsCount = currNeighbors.size();
                uniqueNewNeighbors.clear();
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

    // Instead of using wordList in vector<string> and keeping a separate set<string> for visited,
    // copy it to a unorder_set<string> for faster lookup and removal of visited keys, which enables
    // key finding in unordered_set, according to LC Editorial O(25*k*k+1) or O(k^2) where k is string.size(),
    // instead of explicitly doing string comparison O(nk) where n is wordList.size() and k is string.size().
    vector<string> findNeighbors(string currWord, unordered_set<string>& wordListSet) {
        vector<string> results;
        for (int i = 0; i < currWord.size(); i++) {
            string ori(currWord);
            char oriChar = currWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                currWord[i] = ch;
                if (ch == oriChar || wordListSet.count(currWord) == 0) continue;
                results.emplace_back(currWord);
            }
            currWord[i] = oriChar;
        }
        return results;
    }
};
