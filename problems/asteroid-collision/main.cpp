#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        size_t cntRight = 0;

        for (size_t i = 0; i < asteroids.size(); i++) {
            if (asteroids.at(i) > 0) {
                // right ->
                result.push_back(asteroids.at(i));
                cntRight++;
            }
            else {
                // left <-
                if (cntRight == 0) result.push_back(asteroids.at(i));
                else {
                    int asteroid = abs(asteroids.at(i));
                    int top = result.back();
                    while (result.size() > 0 && top > 0 && top <= asteroid) {
                        result.pop_back();
                        cntRight--;
                        if (top == asteroid) break;
                        if (result.size() != 0) top = result.back();
                    }
                    if (top == asteroid) continue;  // equal size asteroids
                    if (result.size() == 0 || result.back() < 0) {
                        result.push_back(asteroids.at(i));
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    // vector<int> asteroids({5, 10, -5});
    // vector<int> asteroids({-2,-2,1,-2});
    // vector<int> asteroids({1,-1,-2,-2});
    // vector<int> asteroids({1,-2,-2,-2});
    vector<int> asteroids({1,-2,-2,-2,1});
    // vector<int> asteroids({8, -8});
    // vector<int> asteroids({-8, 8});
    // vector<int> asteroids({10,2,-5});
    // vector<int> asteroids({1, -5, 7, -3});
    // vector<int> asteroids({1, 3, 5, -7});
    // vector<int> asteroids({5, 1, -4});
    // vector<int> asteroids({1, 5, -4});
    // vector<int> asteroids({5, 1, 3, 5, -10});

    vector<int> result = s.asteroidCollision(asteroids);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}