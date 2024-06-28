#include <iostream>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class DSU {
public:
    DSU(int sz) : parent(sz), size(sz) {
        for (int i = 0; i < sz; i++) {
            parent[i] = i;
            size[i] = 1;   // initial size for the set
        }
    }
    int find_set(int a) {
        if (a != parent[a]) {
            // path to parent compression
            return parent[a] = find_set(parent[a]);
        }
        return a;
    }
    // union by size (number of accounts combined)
    void union_set(int a, int b) {
        int parent_a = find_set(a);
        int parent_b = find_set(b);
        if (parent_a == parent_b) return;
        if (size[parent_a] >= size[parent_b]) {
            parent[parent_b] = parent_a;
            size[parent_a] += size[parent_b];
        }
        else {
            parent[parent_a] = parent_b;
            size[parent_b] += size[parent_a];
        }
    }
    void print() {
        for (int i = 0; i < parent.size(); i++) {
            cout << i << " " << parent[i] << endl;
        }
    }
private:
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    // LC Editorial soln 2 uses Disjoint Set Union. It runs through all emails in all accounts to populate
    // DSU data structure along with a map of emails to account id. It then runs through the map to construct
    // a map of account id to emails. Finally, it sorts the emails in each account id before returning the merged
    // accounts.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, int> emails;
        DSU dsu(accounts.size());

        // Populate emails map (for unique email) and DSU data structure (for account with duplicate emails)
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (emails.count(accounts[i][j]) == 0) emails[accounts[i][j]] = i;
                else {
                    dsu.union_set(i, emails[accounts[i][j]]);
                }
            }
        }

        // construct combined accounts with unique emails
        unordered_map<int, vector<string>> merged;
        for (auto [email, idx] : emails) {
            merged[dsu.find_set(idx)].push_back(email);
        }

        // process combined accounts and sort emails
        for (auto p : merged) {
            vector<string> account({accounts[p.first][0]});
            sort(p.second.begin(), p.second.end());
            account.insert(account.end(), p.second.begin(), p.second.end());
            res.push_back(account);
        }
        return res;
    }
};
