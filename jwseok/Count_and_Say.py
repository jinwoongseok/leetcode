class Solution:
    def countAndSay(self, n: int) -> str:
        dp = [''] * 31
        dp[0] = '1'
        for i in range(1,n):
            say = dp[i-1]
            next_say = ''
            cnt = 0
            j = 0
            say += 'n'
            while j < len(say)-1:
                cur_char = say[j]
                k = j+1
                while cur_char == say[k]:
                    k += 1
                cnt = k-j
                next_say += str(cnt) + cur_char
                j = k
            dp[i] = next_say
        return dp[n-1]