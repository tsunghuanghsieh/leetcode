import sys
from typing import List

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        diff = sys.maxsize
        nums.sort()
        for i in range(k - 1, len(nums)):
            diff = min(diff, nums[i] - nums[i - (k - 1)])
        return diff
