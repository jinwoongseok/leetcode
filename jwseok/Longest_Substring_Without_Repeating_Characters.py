from collections import Counter


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        right = left = 0
        char = Counter()
        res = 0
        while right < len(s):
            tmp = s[right]
            char[tmp] += 1
            while char[tmp] > 1:
                l = s[left]
                char[l] -= 1
                left += 1
            res = max(res, right-left+1)
            right += 1
        return res
