#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln 1 implementation
    // Stored emails in connected graphs with the first email as the anchor vertex
    // to all other emails in the same account, and use DFS and visited for traversal.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> visited;
        vector<vector<string>> res;

        // construct connected graph
        for (int i = 0; i < accounts.size(); i++) {
            string anchor = accounts[i][1];
            for (int j = 2; j < accounts[i].size(); j++) {
                graph[accounts[i][j]].push_back(anchor);
                graph[anchor].push_back(accounts[i][j]);
            }
        }

        // iterate accounts again to construct merged accounts using iterative dfs
        stack<string> nodes;
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> emails;
            if (visited.count(accounts[i][1])) continue;
            nodes.push(accounts[i][1]);
            while (!nodes.empty()) {
                string email = nodes.top();
                nodes.pop();
                if (visited.count(email)) continue;
                visited.insert(email);
                emails.push_back(email);
                for (int j = graph[email].size() - 1; j >= 0; j--) {
                    nodes.push(graph[email][j]);
                }
            }
            sort(emails.begin(), emails.end());
            vector<string> account({accounts[i][0]});
            account.insert(account.end(), emails.begin(), emails.end());
            res.push_back(account);
        }

        return res;
    }
};
