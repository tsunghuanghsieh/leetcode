#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

//
// Time O(n^2). There are faster solutions O(nlogn) or O(n), but implementation isn't suitable for 1-hr coding interview.
// For example, [Manacher's Algorithm](https://cp-algorithms.com/string/manacher.html) in O(n).
//
// This will use space O(s.size()), 3 * s.size(), 1 for memoization, 1 each for prev1 and prev2 (similar to valid-palindrome-iii).
// itr 0          |itr 1          |itr 2          |itr 3          |itr 4          |itr 5          |itr 6          |itr 7
// c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a
// 1              |1 0            |1 0 1          |1 0 1 0        |1 0 1 0 0      |1 0 1 0 0 0    |1 0 1 0 0 0 0  |1 0 1 0 0 0 0 0
//   1            |  1 0          |  1 0 0        |  1 0 0 0      |  1 0 0 0 0    |  1 0 0 0 0 0  |  1 0 0 0 0 0 0|  1 0 0 0 0 0 0
//     1          |    1 0        |    1 0 0      |    1 0 0 0    |    1 0 0 0 0  |    1 0 0 0 0 0|    1 0 0 0 0 0|    1 0 0 0 0 0
//       1        |      1 0      |      1 0 0    |      1 0 0 0  |      1 0 0 0 1|      1 0 0 0 1|      1 0 0 0 1|      1 0 0 0 1
//         1      |        1 0    |        1 0 1  |        1 0 1 0|        1 0 1 0|        1 0 1 0|        1 0 1 0|        1 0 1 0
//           1    |          1 0  |          1 0 0|          1 0 0|          1 0 0|          1 0 0|          1 0 0|          1 0 0
//             1  |            1 0|            1 0|            1 0|            1 0|            1 0|            1 0|            1 0
//               1|              1|              1|              1|              1|              1|              1|              1
//
// This will use space (s.size()), 1 * s.size() for memoization, and 2 constants.
// itr 0          |itr 1          |itr 2          |itr 3          |itr 4          |itr 5          |itr 6          |itr 7
// c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a|c b c a b c b a
// 1              |1              |1              |1              |1              |1              |1              |1 0 1 0 0 0 0 0
//   1            |  1            |  1            |  1            |  1            |  1            |  1 0 0 0 0 0 0|  1 0 0 0 0 0 0
//     1          |    1          |    1          |    1          |    1          |    1 0 0 0 0 0|    1 0 0 0 0 0|    1 0 0 0 0 0
//       1        |      1        |      1        |      1        |      1 0 0 0 1|      1 0 0 0 1|      1 0 0 0 1|      1 0 0 0 1
//         1      |        1      |        1      |        1 0 1 0|        1 0 1 0|        1 0 1 0|        1 0 1 0|        1 0 1 0
//           1    |          1    |          1 0 0|          1 0 0|          1 0 0|          1 0 0|          1 0 0|          1 0 0
//             1  |            1 0|            1 0|            1 0|            1 0|            1 0|            1 0|            1 0
//               1|              1|              1|              1|              1|              1|              1|              1
//
//
// a a a b   a a a b   a a a b   a a a b
// 1         1 1       1 1 1     1 1 1 0
//   1         1 1       1 1 0     1 1 0
//     1         1 0       1 0       1 0
//       1         1         1         1
//

public:
    int countSubstrings(string s) {
        vector<int> memo(s.size() - 1, 1);
        int count = 0;
        for (int i = s.size() - 2; i >= 0; i--) {
            int prev = 1, temp;
            for (int j = i + 1; j < s.size(); j++) {
                temp = memo[j];
                memo[j] = (s[i] == s[j]) ? prev : 0;
                if (memo[j]) count++;
                prev = temp;
            }
        }
        return count + s.size();
    }
};
