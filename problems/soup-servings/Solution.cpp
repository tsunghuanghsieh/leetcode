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
        vector<pair<int, int>> servings = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
        unordered_map<int, unordered_map<int, double>> seen = {};
        function<double(int, int)> getProbability = [&](int a, int b) -> double {
            int emptyA, emptyB;
            double this_probability = 0;
            for (int i = 0; i < 4; i++) {
                if (seen.find(a) != seen.end() && seen[a].find(b) != seen[a].end()) {
                    this_probability += 0.25 * seen[a][b];
                    continue;
                }
                int remainingA = a - servings[i].first;
                int remainingB = b - servings[i].second;
                emptyA = remainingA <= 0;
                emptyB = remainingB <= 0;
                if (emptyA && emptyB) {
                    this_probability += 0.5 * 0.25;
                } else if (emptyA) {
                    this_probability += 1 * 0.25;
                } else if (emptyB) {
                    // do nothing
                    this_probability += 0 * 0.25;
                } else {
                    this_probability += 0.25 * getProbability(remainingA, remainingB);
                }
            }
            seen[a][b] = this_probability;
            return this_probability;
        };
        //
        // This runs faster on leetcode
        //
        // function<double(int, int)> getProbability = [&](int a, int b) -> double {
        //     double this_probability = 0;
        //     if (seen.find(a) != seen.end() && seen[a].find(b) != seen[a].end()) {
        //         return seen[a][b];
        //     }
        //     if (a <= 0 && b <= 0) {
        //         this_probability = 0.5;
        //     } else if (a <= 0) {
        //         this_probability = 1;
        //     } else if (b <= 0) {
        //         // do nothing
        //         this_probability = 0;
        //     } else {
        //         this_probability = 0.25 * (getProbability(a - 100, b) + getProbability(a - 75, b - 25) +
        //                                    getProbability(a - 50, b - 50) + getProbability(a - 25, b - 75));
        //     }
        //     seen[a][b] = this_probability;
        //     return this_probability;
        // };

        // empirical data shows probability is 1.0 when n > 4800.
        // without this, the execution will take ~500ms longer.
        if (n > 4800) return 1.0;
        for (int i = 0; i < n + 25; i += 25) {
            probability = getProbability(i, i);
            if (probability > 1 - 1e-5) return 1.0;
        }
        return probability;
    }
};
