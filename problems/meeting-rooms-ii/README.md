# [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) (**Premium**)

Given an array of meeting time intervals intervals where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, return _the minimum number of conference rooms required_.

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

**Constraints:**
* <code>1 <= intervals.length <= 10<sup>4</sup></code>
* <code>0 <= start<sub>i</sub> < end<sub>i</sub> <= 10<sup>6</sup></code>

## Runtime
`map::find()` and `map::[]` runtime is O(log n) where `n` is `map::size()` which contains both starting and ending time of meeting time intervals. It runs through all meeting time intervals, `m`, which is half of `n`. So the runtime complexity is O(m log n).

## Interview
Third most asked interview question by Facebook per [this](https://www.youtube.com/watch?v=PWgFnSygweI).

As of 07/06/2025, leetcode premium subscription says Amazon 18 times, Google 12 times and Facebook 5 times in the last 3 months.

As of 06/25/2019, leetcode premium subscription says Facebook 49 times, Google 27 times and Amazon 24 times in the last 6 months.
