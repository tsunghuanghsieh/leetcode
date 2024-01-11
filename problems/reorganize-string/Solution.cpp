#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int maxChar = 0;
        vector<int> freq(26, 0);
        priority_queue<vector<int>> pq;
        stringstream ss;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            maxChar = (freq[s[i] - 'a'] > freq[maxChar]) ? s[i] - 'a' : maxChar;
        }
        if (freq[maxChar] - 1 > (s.size() - 1) / 2) {
            return "";
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({freq[i], 'a' + i});
        }
        while (!pq.empty()) {
            vector<int> chFirst = pq.top();
            pq.pop();
            chFirst[0]--;
            ss << char(chFirst[1]);
            if (pq.empty()) break;
            vector<int> chSecond = pq.top();
            pq.pop();
            chSecond[0]--;
            ss << char(chSecond[1]);
            if (chFirst[0] > 0) pq.push(chFirst);
            if (chSecond[0] > 0) pq.push(chSecond);
        }

        return ss.str();
    }
};
