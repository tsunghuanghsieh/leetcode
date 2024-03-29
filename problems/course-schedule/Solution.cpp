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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adj(numCourses);
        stack<int> stk;
        int count = 0;

        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i].front()]++;   // in degree presents the number of prereqs
            adj[prerequisites[i].back()].push_back(prerequisites[i].front());
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) stk.push(i);   // pushing possible starting courses
        }

        while (!stk.empty()) {
            int course = stk.top();
            stk.pop();
            for (int i = 0; i < adj[course].size(); i++) {
                // decrement prereq count and push only when all prereqs are fulfilled (== 0)
                if (--inDegree[adj[course][i]] == 0) stk.push(adj[course][i]);
            }
            count++;
        }
        // when a loop exists in the directed graph, resulting count will be smaller.
        return (numCourses == count) ? true : false;
    }
};
