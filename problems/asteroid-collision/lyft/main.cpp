#include <iostream>
#include <vector>
using namespace std;

class Asteroid {
public:
    Asteroid(int direction, int mass): _direction(direction), _mass(mass) {}
    int getDirection();
    int getMass();
private:
    int _direction;
    int _mass;
};

class Solution {
public:
    // Number of asteroids going right after collision
    // No mass loss after collision
    vector<Asteroid> asteroidCollision1(vector<Asteroid>& asteroids) {
        vector<Asteroid> result;

        for (size_t i = 0; i < asteroids.size(); i++) {
            if (asteroids.at(i).getDirection() > 0) {
                // right ->
                result.push_back(asteroids.at(i));
            }
            else {
                // left <-
                if (result.size() == 0) {
                    continue;
                }
                else {
                    for (size_t j = result.size(); j > 0; j--) {
                        int last = result.back().getMass();
                        if (last > asteroids.at(i).getMass()) break; // larger -> <- smaller
                        result.pop_back();
                        if (last == asteroids.at(i).getMass()) break; // same -> <- same
                    }
                }
            }
        }
        return result;
    }

    // Number of asteroids going right after collision
    // Mass loss after collision
    vector<Asteroid> asteroidCollision2(vector<Asteroid>& asteroids) {
        vector<Asteroid> result;

        for (size_t i = 0; i < asteroids.size(); i++) {
            if (asteroids.at(i).getDirection() > 0) {
                // right ->
                result.push_back(asteroids.at(i));
            }
            else {
                // left <-
                if (result.size() == 0) {
                    continue;
                }
                else {
                    int asteroidMass = asteroids.at(i).getMass();
                    for (size_t j = result.size(); j > 0; j--) {
                        int newMass = result.back().getMass() - asteroidMass;
                        if (newMass >= 0) {
                            result.pop_back();
                            Asteroid resultant(1, newMass);
                            if (newMass > 0) result.push_back(resultant);
                            break;
                        }
                        else {
                            result.pop_back();
                            asteroidMass = abs(newMass);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<Asteroid> asteroids;
    // test
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(1, 10));
    // asteroids.push_back(Asteroid(-1, 5));

    // test
    // asteroids.push_back(Asteroid(-1, 2));
    // asteroids.push_back(Asteroid(-1, 2));
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(-1, 2));

    // test
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(-1, 1));
    // asteroids.push_back(Asteroid(-1, 2));
    // asteroids.push_back(Asteroid(-1, 2));

    // test
    // asteroids.push_back(Asteroid(1, 8));
    // asteroids.push_back(Asteroid(-1, 8));

    // test
    asteroids.push_back(Asteroid(-1, 8));
    asteroids.push_back(Asteroid(1, 8));

    // test
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(-1, 5));
    // asteroids.push_back(Asteroid(1, 7));
    // asteroids.push_back(Asteroid(-1, 3));

    // test
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(1, 3));
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(-1, 7));

    // test
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(-1, 4));

    // test
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(-1, 4));

    // test
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(1, 1));
    // asteroids.push_back(Asteroid(1, 3));
    // asteroids.push_back(Asteroid(1, 5));
    // asteroids.push_back(Asteroid(-1, 10));


    vector<Asteroid> result1 = s.asteroidCollision1(asteroids);
    cout << result1.size() << endl;
    vector<Asteroid> result2 = s.asteroidCollision2(asteroids);
    cout << result2.size() << endl;
    return 0;
}