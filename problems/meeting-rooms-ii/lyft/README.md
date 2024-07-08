# Lyft variant

A "job" is a programming task that runs unattended. Suppose you have a list of jobs and you can spawn workers that can execute the jobs. Given a list of jobs for the next day and the amount of time each job takes to run, create a scheduler that schedules the jobs such that you complete all of them using the least number of workers possible.

The following are the specifications for the job scheduler:
1. Once a worker is created, it can be used for as many jobs as you want, but can only work on one job at a time.
2. The job scheduler should pick the worker with the lowest index if there are multiple workers available.
    1. Workers are assigned an index, starting at `0` for the first worker, `1` for the second and so on.

The following describes the format of the input:
1. Number of jobs to run `N`
2. Followed by `N` lines each with the start time `<start-time:string>` of the job and the time take `<duration:integer>` by the job to complete.
    1. `start-time` is provided in the 24-hour format. For example, `0323`, `0014`, `2359` are all valid start times.
    2. The unit for `duration` is minutes. A job starting at `0323` and taking `122` minutes will end at `0525` and the worker running the job will be free to run a new job at `0526`.

Finally, please note that the number of jobs to be scheduled is of the order of ~100k.

**Note:**
1. Assume that the input will never be malformed.
2. Assume that all the jobs defined in the input will start and end in a single day (meaning that they will run between 0000 hours to 2359 hours).
3. Assume that no two jobs will have the same start time.
4 The job definition in the input are unordered.

**Sample Input**
```
10
0000 30
0015 16
0020 11
0030 10
0031 12
0040 10
0045 5
0051 11
0059 1
0058 2
```

**Sample Output**
```
4
J0 W0
J1 W1
J2 W2
J3 W3
J4 W0
J5 W1
J6 W0
J7 W0
J8 W2
J9 W1
```