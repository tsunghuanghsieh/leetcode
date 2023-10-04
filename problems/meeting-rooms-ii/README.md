# [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) (**Premium**)

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (s<sub>i</sub> < e<sub>i</sub>), find the minimum number of conference rooms required.

**Example 1:**
```
Input: [[0,30],[5,10],[15,20]]
Output: 2
```
**Example 2:**
```
Input: [[7,10],[2,4]]
Output: 1
```

## Runtime
`map::find()` and `map::[]` runtime is O(log n) where `n` is `map::size()` which contains both starting and ending time of meeting time intervals. It runs through all meeting time intervals, `m`, which is half of `n`. So the runtime complexity is O(m log n).

## Interview
Third most asked interview question by Facebook per [this](https://www.youtube.com/watch?v=PWgFnSygweI).

As of 06/25/2019, leetcode premium subscription says Facebook 49 times, Google 27 times and Amazon 24 times in the last 6 months.
