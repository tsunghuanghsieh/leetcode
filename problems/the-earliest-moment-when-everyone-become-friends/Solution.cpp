#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Dsu {
public:
    Dsu(int size) : count(0) {
        nums.resize(size, -1);
    }

    int getCount() { return count; }

    int findParent(int a) {
        if (nums[a] == -1) return nums[a];
        return (nums[a] != a) ? (nums[a] = findParent(nums[a])) : a;
    }

    void joinSets(int a, int b) {
        int ap = findParent(a);
        int bp = findParent(b);
        if (ap == -1 && bp == -1) {
            nums[a] = nums[b] = min(a, b);
            count++;
        }
        else if (ap == -1) nums[a] = bp;
        else if (bp == -1) nums[b] = ap;
        else if (ap != bp) {
            nums[b] = nums[bp] = ap;
            count--;
        }
    }
private:
    vector<int> nums;
    int count;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        unordered_set<int> nums;
        Dsu dsu(n);
        sort(logs.begin(), logs.end());
        for (vector<int> log : logs) {
            nums.insert({log[1], log[2]});
            dsu.joinSets(log[1], log[2]);
            if (nums.size() == n && dsu.getCount() == 1) return log[0];
        }
        return -1;
    }
};
