#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // LC soln #1: Path Search in Graph (DFS)
    // LC soln #2: Union find with weight
    //
    // This implememtation matches LC soln #1.
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> results;
        // build graph
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            if (graph.count(queries[i][0]) == 0 || graph.count(queries[i][1]) == 0) {
                results.emplace_back(-1);
            }
            else {
                unordered_set<string> visited;
                double result = dfs(queries[i][0], queries[i][1], graph, visited, 1);
                results.push_back(result);
            }
        }
        return results;
    }
private:
    double dfs(string origin, string& dest, unordered_map<string, unordered_map<string, double>>& graph,
        unordered_set<string>& visited, double value) {
        if (origin == dest) return value;
        visited.insert(origin);
        for (auto& [neighbor, weight] : graph[origin]) {
            if (visited.count(neighbor)) continue;
            double result = dfs(neighbor, dest, graph, visited, value * weight);
            if (result != -1.0) return result;
        }
        return -1.0;
    }

    void print2dString(vector<vector<string>>& vv) {
        for (int i = 0; i < vv.size(); i++) {
            for (int j = 0; j < vv[0].size(); j++) {
                cout << vv[i][j] << " ";
            }
            cout << endl;
        }
    }
};
