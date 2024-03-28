#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // For reading
    // https://medium.com/@vinay.vashist2003/graphs-data-structure-in-c-ab7b4205f41a
    //
    // Using Kahn's algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses), res;
        map<int, vector<int>> adj;
        stack<int> stk;

        for (int i = 0; i < prerequisites.size(); i++) {
            inDegrees[prerequisites[i].front()]++;   // in degree presents the number of prereqs
            adj[prerequisites[i].back()].push_back(prerequisites[i].front());
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) stk.push(i);   // pushing possible starting courses
        }
        while (!stk.empty()) {
            int course = stk.top();
            stk.pop();
            for (int i = 0; i < adj[course].size(); i++) {
                // decrement prereq count and push only when all prereqs are fulfilled (== 0)
                if (--inDegrees[adj[course][i]] == 0) stk.push(adj[course][i]);
            }
            res.push_back(course);
        }
        // when a loop exists in the directed graph, resulting vector will be short.
        return (res.size() == numCourses) ? res : vector<int>();
    }
};
