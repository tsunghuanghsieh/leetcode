#include <iostream>
#include <regex>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> ptime;
        stack<stack<int>> stkOthers;
        regex patternLog("(\\d+):(\\w+):(\\d+)");
        for (auto log : logs) {
            sregex_token_iterator itr(log.begin(), log.end(), patternLog, {1, 2, 3});
            int id = stoi((*itr++).str());
            string op = *itr++;
            int t = stoi((*itr).str());
            if (op == "start") {
                ptime.push(t);
                stkOthers.push(stack<int>());
            }
            else {
                int duration = t - ptime.top() + 1;
                stack<int> curr = stkOthers.top();
                stkOthers.pop();
                int curr_total = 0;
                while (curr.size() > 0) {
                    curr_total += curr.top();
                    curr.pop();
                }
                if (stkOthers.size() > 0) stkOthers.top().push(duration);
                res[id] += duration - curr_total;
                ptime.pop();
            }
        }
        return res;
    }
};
