#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LC soln #1 uses DFS approach
    // LC soln #2 uses BFS approach
    // LC soln #3 uses Union-Find approach.
    //
    // Copilot autocompleted code
    //
    // The Union-Find approach is the most efficient for this problem.
    // Union-Find (Disjoint Set Union) approach
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // where N is the number of cities (nodes)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (uf.find(i) == i) {
                provinces++;
            }
        }
        return provinces;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n) : parent(n), rank(n, 1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void unionSet(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    private:
        vector<int> parent;
        vector<int> rank;
    };
};
