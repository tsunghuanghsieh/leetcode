#include <set>
#include <vector>

using namespace std;

// Another approach is to sort nums then compare adjacent values.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end()) return true;
            s.emplace(num);
        }
        return false;
    }
};