#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
// In all LC editorial solutions, they all take a substring, length 1 to entire string, of s
// and compare it to wordDict. It will be inefficient when substring is shorter or longer than all words
// in wordDict.
//
// Instead, my approach is to take words in wordDict and compare them to s. If a match is found,
// repeat the comparisons at the new starting index until the end of s. Otherwise, s cannot be constructed
// using words in wordDict.
//
// After that, reconstruct the sentences from visited using dfs. The sentence is valid only when it ends on
// position s.size().
//
// all possible permutations
// 00 01 02 03 04 05 06 07 08 09 10 11 12 13
//  c  a  t  s  a  n  d  d  o  g  s  a  n  d
//  3        7          10       14           cat sand dog sand
//  3        7          11          14        cat sand dogs and
//  4           7       10       14           cats and dog sand
//  4           7       11          14        cats and dogs and
//
// recorded in visited
// 00 01 02 03 04 05 06 07 08 09 10 11 12 13
//  c  a  t  s  a  n  d  d  o  g  s  a  n  d
//  3        7          10       14
//  4           7       11          14

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        visited.resize(s.size());
        findWordBreak(s, 0, wordDict, 0);
        vector<string> res;
        constructString(s, 0, "", res);
        return res;
    }
private:
    vector<unordered_set<int>> visited;

    void findWordBreak(string &s, int sidx, vector<string>& wordDict, int wdidx) {
        if (sidx >= s.size()) return;

        int pos = s.find(wordDict[wdidx], sidx);
        if (pos == sidx) {
            if (visited[sidx].count(sidx + wordDict[wdidx].size()) > 0) return;
            else {
                findWordBreak(s, sidx + wordDict[wdidx].size(), wordDict, 0);
                visited[sidx].insert(sidx + wordDict[wdidx].size());
            }
        }
        if (wdidx + 1 < wordDict.size()) findWordBreak(s, sidx, wordDict, wdidx + 1);
    }

    void constructString(string &s, int sidx, string sentence, vector<string>& res) {
        if (sidx == s.size()) {
            res.emplace_back(sentence);
            return;
        }
        for (int pos : visited[sidx]) {
            string temp = sentence;
            if (sidx != 0) temp.append(" ");
            temp.append(s.substr(sidx, pos - sidx));
            constructString(s, pos, temp, res);
        }
    }
};
