from collections import Counter
from typing import List

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        wfreq = Counter(c for c in chars)
        sum = 0
        for s in words:
            sfreq = {}
            valid = True
            for c in s:
                sfreq[c] = sfreq.get(c, 0) + 1
                if c not in wfreq and sfreq[c] > wfreq[c]:
                    valid = False
                    break

            if valid is True:
                sum += len(s)
        return sum
