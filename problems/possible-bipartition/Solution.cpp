#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // LC Editorial soln #3: union find
    //
    // Use union find for number graphs.
    // vector<int> parent to represent number-parent (dislike) relationship.
    // unordered_map<int, int> distance
    //
    // The logic is to assign distance (rank) among numbers. The first one has distance 0.
    // Its dislike (2nd) number has distance 1. The 2nd's dislike number has distance 2 from
    // the first one. So on and so forth. Even distance in 1 group and old in the other.
    // If any number pair in dislikes are in the same group, it is then impossible to partition.
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        bool res = true;
        parent.resize(n + 1);   // use numbers in dislikes as is
        iota(parent.begin(), parent.end(), 0);   // requires numeric
        for (int i = 0; i < dislikes.size(); i++) {
            setUnion(dislikes[i][0], dislikes[i][1]);
            res = checkUnion(dislikes[i][0], dislikes[i][1]);
            if (!res) return res;
        }
        return res;
    }
private:
    vector<int> parent;   // index: number, value: dislike number
    unordered_map<int, int> distance;   // key: number, value: distance from the first dislike number

    int findParent(int a) {
        if (a != parent[a]) {
            int p = findParent(parent[a]);
            // update distance[a] after upddating distance[parent[a]] in recursive findParent calls
            distance[a] += distance[parent[a]];
            parent[a] = p;
        }
        return parent[a];
    }

    bool checkUnion(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == pb) return distance[a] % 2 != distance[b] % 2;
        return true;
    }

    void setUnion(int a, int b) {
        if (distance.count(a) == 0) distance[a] = 0;
        if (distance.count(b) == 0) distance[b] = 0;
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa != pb) {
            if (distance[a] == 0 && distance[b] == 0) {
                // both new or the first number in its graph
                parent[pb] = pa;
                distance[pb] = 1;
            }
            else if (pa == a) {
                // a is new or the first number in its graph
                parent[pa] = pb;
                distance[pa] = distance[b] + 1;
            }
            else if (pb == b) {
                // b is new or the first number in its graph
                parent[pb] = pa;
                distance[pb] = distance[a] + 1;
            }
            else {
                // both already in its graph
                parent[pb] = parent[b] = pa;   // update parent of b and pb
                // update distance of pb
                // need to adjust distance by 1 only when b is in the same group as pb
                distance[pb] = distance[a] + (distance[b] % 2 == 0);
                distance[b] += distance[pb];   // update distance of b
            }
        }
    }
};
