#include <iostream>
#include <vector>

using namespace std;

class Dsu {
public:
    Dsu (int n) : vertices(n + 1) {
        // initialize each vertex to itself, 1 to n
        for (int i = 1; i <= n; i++) vertices[i] = i;
    }

    int findParent(int a) {
        // return itself (root) or it's parent with path compression
        return (vertices[a] != a) ? vertices[a] = findParent(vertices[a]) : a;
    }

    void findUnion(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == a && pb == b) {
            vertices[a] = vertices[b] = b;
        }
        else if (pa == a) vertices[a] = pb;
        else if (pb == b) vertices[b] = pa;
        else if (pa != pb) {
            vertices[a] = vertices[pa] = pb;
        }
    }

private:
    vector<int> vertices;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        Dsu dsu(edges.size());
        for (int e = 0; e < edges.size(); e++) {
            int pa = dsu.findParent(edges[e][0]), pb = dsu.findParent(edges[e][1]);
            if (pa == pb) {
                // redundant edge, vertices already connected
                res = {edges[e][0], edges[e][1]};
                break;
            }
            dsu.findUnion(edges[e][0], edges[e][1]);
        }
        return res;
    }
};
