#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortTopological(map<int, vector<int>> input) {
        set<int> keys, vals, start;
        vector<int> linearization;

        getKeyValueSets(keys, vals, input);
        map<int, int> edges = getEdges(input);

        for (int key : keys) {
            if (vals.count(key) == 0) start.insert(key);
        }

        // min priority queue
        priority_queue<int, vector<int>, greater<int>> nodes(start.begin(), start.end());

        // 1: 0
        // 2: 0
        // 3: 1
        // 4: 1
        // 5: 2
        // 6: 1
        // 7: 1
        // 9: 0
        while (!nodes.empty()) {
            int curr = nodes.top();
            // elements in nodes don't have other element(s) pointing to them
            // cout << curr << endl;
            linearization.push_back(curr);
            nodes.pop();
            for (int val : input[curr]) {
                if (edges[val] == 1) {
                    // once curr is popped, val will not have any element pointing to it
                    nodes.push(val);
                }
                edges[val]--;
                if (edges[val] == 0) edges.erase(val);
            }
        }
        return linearization;
    }

    // print input
    void printInput(map<int, vector<int>> input) {
        for (pair<int, vector<int>> node : input) {
            cout << node.first << ": [";
            for (int i = 0; i < input[node.first].size(); i++) {
                cout << node.second[i];
                if (i + 1 != input[node.first].size()) cout << ",";
            }
            cout << "]" << endl;
        }
    }
private:
    map<int, int> getEdges(map<int, vector<int>> input) {
        map<int, int>result;
        for (auto node : input) {
            for (int v : node.second) {
                // for node[v], count how many incoming edges it has
                result[v] = result[v] + 1;
            }
        }
        // for (auto node : result) {
        //     cout << node.first << " " << node.second << endl;
        // }
        return result;
    }

    void getKeyValueSets(set<int>& keys, set<int>& vals, map<int, vector<int>>& input) {
        for (pair<int, vector<int>> node : input) {
            keys.insert(node.first);
            for (int v : node.second) {
                vals.insert(v);
            }
        }
    }

    void printSet(set<int> s) {
        for (int num : s) {
            cout << num << " ";
        }
        cout << endl;
    }
};
