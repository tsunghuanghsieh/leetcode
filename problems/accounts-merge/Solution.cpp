#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln 1 stored emails in connected graphs and use DFS and visited for traversal.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, int> unique_emails;
        // initial implementaion was to store email strings, but string insert/clear is slower than int.
        // without duplicate emails, the index stores itself
        // with duplicate emails, the smallest index stores all other indices, the others is an empty set
        vector<unordered_set<int>> bkt_emails(accounts.size());
        for (int i = 0; i < accounts.size(); i++) {
            set<int> conflicts;
            for (int j = 1; j < accounts[i].size(); j++) {
                auto itr = unique_emails.find(accounts[i][j]);
                if (itr == unique_emails.end()) {
                    unique_emails[accounts[i][j]] = i;
                }
                else {
                    conflicts.insert((*itr).second);
                }
            }
            bkt_emails[i].insert(i);
            if (conflicts.size() > 0) {
                conflicts.insert(i);
                auto itr = conflicts.begin();
                for (++itr; itr != conflicts.end(); itr++) {
                    for (auto itr_e = bkt_emails[*itr].begin(); itr_e != bkt_emails[*itr].end(); itr_e++) {
                        for (int j = 1; j < accounts[*itr_e].size(); j++) {
                            unique_emails[accounts[*itr_e][j]] = *conflicts.begin();
                        }
                    }
                    bkt_emails[*conflicts.begin()].insert(bkt_emails[*itr].begin(), bkt_emails[*itr].end());
                    bkt_emails[*itr].clear();
                }
            }
        }
        for (int i = 0; i < bkt_emails.size(); i++) {
            if (bkt_emails[i].size() > 0) {
                unordered_set<string> emails;
                for (int idx : bkt_emails[i]) {
                    for (int j = 1; j < accounts[idx].size(); j++) {
                        emails.insert(accounts[idx][j]);
                    }
                }
                vector<string> account(emails.begin(), emails.end());
                sort(account.begin(), account.end());
                account.insert(account.begin(), accounts[i][0]);
                res.emplace_back(account);
            }
        }
        return res;
    }
};
