# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         strlen = len(s)
#         reverse_s = s[::-1]
#         dp = [[0 for _ in range(strlen)] for _ in range(strlen)]
#         max_len = 0
#         max_end = 0
#         for i in range(strlen):
#             for j in range(strlen):
#                 if s[i] == reverse_s[j]:
#                     if i == 0 or j == 0:
#                         dp[i][j] = 1
#                     else:
#                         dp[i][j] = dp[i-1][j-1] + 1
#                 if dp[i][j] > max_len:
#                     # we need to check indices origin and reverse
#                     if i - dp[i][j] + 1 == strlen - j - 1:
#                         max_len = dp[i][j]
#                         max_end = i
#         return s[max_end - max_len + 1:max_end + 1]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        strlen = len(s)
        for i in range(strlen):
            tmp = self.getSubstring(s, i, i)
            if len(tmp) > len(res):
                res = tmp

            tmp = self.getSubstring(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp
        return res

    def getSubstring(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]