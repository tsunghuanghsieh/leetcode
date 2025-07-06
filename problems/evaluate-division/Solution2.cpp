#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution2 {
public:
    // LC soln #1: Path Search in Graph (DFS)
    // LC soln #2: Union find with weight
    //
    // This implememtation matches LC soln #2.
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> results;
        // build union-set
        for (int i = 0; i < equations.size(); i++) {
            unionSet(equations[i][0], equations[i][1], values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (parent.count(queries[i][0]) == 0 || parent.count(queries[i][1]) == 0) {
                results.emplace_back(-1);
            }
            else {
                results.emplace_back(unionFind(queries[i][0], queries[i][1]));
            }
        }
        return results;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    void add(string& a) {
        if (parent.count(a) == 0) {
            parent[a] = a;
            weight[a] = 1.0;
        }
    }

    string findParent(string x) {
        if (parent[x] != x) {
            string p = findParent(parent[x]);
            weight[x] *= (weight[parent[x]] * weight[p]);
            return parent[x] = p;
        }
        return x;
    }

    void print2dString(vector<vector<string>>& vv) {
        for (int i = 0; i < vv.size(); i++) {
            for (int j = 0; j < vv[0].size(); j++) {
                cout << vv[i][j] << " ";
            }
            cout << endl;
        }
    }

    double unionFind(string& a, string &b) {
        string pa = findParent(a);
        string pb = findParent(b);
        if (pa == pb) {
            return weight[b] / weight[a];
        }
        return -1.0;
    }

    void unionSet(string& a, string &b, double val) {
        add(a);
        add(b);
        string pa = findParent(a);
        string pb = findParent(b);
        if (pa != pb) {
            parent[pb] = pa;
            weight[pb] = weight[a] * val / weight[b];
        }
    }
};
