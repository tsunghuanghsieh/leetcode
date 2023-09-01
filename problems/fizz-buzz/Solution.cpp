#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; i++) {
            string word;
            if (i % 3 == 0) {
                word = "Fizz";
            }
            if (i % 5 == 0) {
                word += "Buzz";
            }
            if (word.size() == 0) word += std::to_string(i);
            answer.emplace_back(word);
        }
        return answer;
    }
};