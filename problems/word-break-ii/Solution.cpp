#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
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
        if (wdidx == wordDict.size() && sidx != s.size()) return;

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
