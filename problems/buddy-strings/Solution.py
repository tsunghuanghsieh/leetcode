class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False
        if s == goal: return len(set(s)) < len(s)   # identical string, need at least 1 duplicate
        # chatgpt version for the same logic below
        # diffs = [(a, b) for a, b in zip(s, goal) if a != b]
        # return (len(diffs) == 2 and diffs[0][0] == diffs[1][1] and diffs[0][1] == diffs[1][0])
        diff_count = 0
        diff_index = None
        for i in range(len(s)):
            if s[i] != goal[i]:
                if diff_index is None: diff_index = i
                diff_count += 1
                if diff_count == 2:
                    if s[diff_index] != goal[i] or s[i] != goal[diff_index]: return False
                elif diff_count > 2: return False
        if diff_count == 1: return False
        return True
