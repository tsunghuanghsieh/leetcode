class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        roman = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
        prev = None
        for i in range(len(s)):
            if i + 1 < len(s) and roman[s[i]] < roman[s[i + 1]]:
                prev = roman[s[i]]
            elif prev is None:
                num += roman[s[i]]
            else:
                num += (roman[s[i]] - prev)
                prev = None

        return num
