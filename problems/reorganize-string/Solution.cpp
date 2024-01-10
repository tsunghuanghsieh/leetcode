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
        char maxChar = 0;
        map<char, int> freq;
        priority_queue<vector<int>> pq;
        stringstream ss;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            maxChar = (maxChar == 0 || freq[s[i]] > freq[maxChar]) ? s[i] : maxChar;
        }
        if (freq[maxChar] - 1 > (s.size() - 1) / 2) {
            return "";
        }
        for (pair<char, int> p : freq) {
            pq.push({p.second, p.first - 'a'});
        }
        cout << freq.size() << endl;
        while (!pq.empty()) {
            vector<int> chFirst = pq.top();
            pq.pop();
            chFirst[0]--;
            ss << char(chFirst[1] + 'a');
            if (pq.empty()) break;
            vector<int> chSecond = pq.top();
            pq.pop();
            chSecond[0]--;
            ss << char(chSecond[1] + 'a');
            if (chFirst[0] > 0) pq.push(chFirst);
            if (chSecond[0] > 0) pq.push(chSecond);
        }

        return ss.str();
    }
};
