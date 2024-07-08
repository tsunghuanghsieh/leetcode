#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    map<string, int> getWorkerAssignment(map<string /* startTime */, string /* endTime */> jobs) {
        map<string /* job startTime */, int /* job worker id */> jobWorker;
        for (map<string, string>::iterator itrJob = jobs.begin(); itrJob != jobs.end(); itrJob++) {
            // find all jobs finished before start time of incoming job
            // excluding jobs ending at the same time as start time of the incoming job
            auto itrFirstUnfinished = endTimes.lower_bound(itrJob->first);
            updateavailableWorkers(endTimes.begin(), itrFirstUnfinished);
            endTimes.erase(endTimes.begin(), itrFirstUnfinished);
            int nextAvailableWorker = assignNextWorker();
            jobWorker[itrJob->first] = nextAvailableWorker;
            if (itrFirstUnfinished == endTimes.end()) {
                // all jobs finished before start time of incoming job
                endTimes.insert(make_pair(itrJob->second, vector<int>({nextAvailableWorker})));
            }
            else {
                // insert end time of incoming job
                auto itrEndTime = endTimes.find(itrJob->second);
                if (itrEndTime != endTimes.end()) {
                    vector<int> workers = itrEndTime->second;
                    workers.push_back(nextAvailableWorker);
                    itrEndTime->second = workers;
                }
                else {
                    endTimes.insert(make_pair(itrJob->second, vector<int>({nextAvailableWorker})));
                }
            }
        }

        return jobWorker;
    }

    string calculateEndTime(string startTime, string duration) {
        ostringstream oss;
        int start = atoi(startTime.c_str());
        int lapsedTime = getLapsedTime(duration);
        int endTime = start + lapsedTime;
        if (endTime % 100 >= 60) {
            endTime = endTime - 60 + 100;
        }
        oss << std::setfill('0') << std::setw(4) << endTime;
        return oss.str();
    }

    int getWorkerCount() {
        return cntWorker;
    }
private:
    int assignNextWorker() {
        int workerId = 0;
        if (availableWorkers.size() != 0) {
            workerId = availableWorkers.begin()->first;
            availableWorkers.erase(availableWorkers.begin());
            return workerId;
        }
        workerId = cntWorker;
        cntWorker++;
        return workerId;
    }

    /* helper function to convert minutes into hours and minutes */
    /* 150 minutes => 230 */
    int getLapsedTime(string duration) {
        int result;
        int minutes = atoi(duration.c_str());
        result = minutes / 60 * 100 + minutes % 60;
        return result;
    }

    void updateavailableWorkers(map<string, vector<int>>::iterator from, map<string, vector<int>>::iterator to) {
        for (auto it = from; it != to; it++) {
            // add workers freed up back to the pool
            vector<int> workers = it->second;
            for (int w = 0; w < workers.size(); w++) {
                availableWorkers[workers[w]] = 1;
            }
        }
    }

    map<string /* job's end time */, vector<int> /* worker id list */> endTimes; // job end time with worker ids
    map<int /* worker id */, int /* noop */> availableWorkers; // available workers, could be replaced with set
    int cntWorker = 0; // number of workers
};
