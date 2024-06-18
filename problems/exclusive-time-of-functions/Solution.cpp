#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    // The initial approach was to keep track of timestamps in a stack, and a stack of stacks
    // for the running sums of durations for other processes at each start of a process, so that
    // when the process ends, it will subtract the running sum of durations for all other process
    // between the current process' start and end. The current running sum will then be added to
    // the top of the stack. This is not efficient when the stack runs deep.
    //
    // A better approach is to calculate the duration for the current process at each timestamp in the log
    // as logs are processed. It just needs the last and the current timestamp to calculate duration.
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> pid;
        int prev_t;
        for (auto log : logs) {
            int id, t;
            char op[6];
            // use sscanf to read int and char array
            sscanf(log.c_str(), "%d:%[a-z]:%d", &id, op, &t);
            if (op[0] == 's') {
                if (!pid.empty()) {
                    // - 1 to offset the + 1 while handling the end event.
                    res[pid.top()] += t - prev_t - 1;
                }
                prev_t = t;
                pid.push(id);
            }
            else {
                // This would pass test case 121 where a process not currently being executed ends and
                // pops another process currently being executed off the stack.
                res[pid.top()] += t - prev_t + 1;

                // This follows the understanding that only currently executed process can pop itself off the stack
                // and fails test case 121.
                // res[id] += t - prev_t + 1;
                prev_t = t;
                pid.pop();
            }
        }
        return res;
    }
};
