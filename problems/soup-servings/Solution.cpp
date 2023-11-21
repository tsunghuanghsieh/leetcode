#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // The initial approach was to use bottom-up dynamic programming to calculate probability of n.
    // However, when n is large, say 10^9, the recursion depth is 10^7 for 100ml and 4 x 10^7 for 25ml alone.
    // The execution will crash because the call stack is too big, even with memoization.
    // In README.md, problem description says "Answers within 10^-5 of the actual answer will be accepted".
    // Turns out, it's not a suggestion but a requirement. It meant to not do the calculation when the
    // probability is > 0.99999, and simply return 1.000000. Probability will approach 1 relatively quickly.
    // With that, we will do it iteratively with small n until the probability becomes > 0.99999.
    double soupServings(int n) {
        double probability = 0.0;
        for (int i = 0; i < n + 25; i += 25) {
            probability = getProbability(i, i);
            if (probability > 1 - 1e-5) return 1.0;
        }
        return probability;
    }
private:
    vector<pair<int, int>> servings = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    unordered_map<int, unordered_map<int, double>> seen = {};
    double getProbability(int a, int b) {
        int emptyA, emptyB;
        double probability = 0;
        for (int i = 0; i < 4; i++) {
            if (seen.find(a) != seen.end() && seen[a].find(b) != seen[a].end()) {
                probability += 0.25 * seen[a][b];
                continue;
            }
            int remainingA = a - servings[i].first;
            int remainingB = b - servings[i].second;
            emptyA = remainingA <= 0;
            emptyB = remainingB <= 0;
            if (emptyA && emptyB) {
                probability += 0.5 * 0.25;
            } else if (emptyA) {
                probability += 1 * 0.25;
            } else if (emptyB) {
                // do nothing
                probability += 0 * 0.25;
            } else {
                probability += 0.25 * getProbability(remainingA, remainingB);
            }
        }
        seen[a][b] = probability;
        return probability;
    }
};
