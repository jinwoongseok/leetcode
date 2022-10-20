class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        parentheses = []
        def dfs(cnt, cur, ret):
            if cnt < 0 or len(cur) > n*2:
                return
            if cnt == 0 and len(cur) == n*2:
                ret.append(cur)
                return
            dfs(cnt+1, cur+'(', ret)
            dfs(cnt-1, cur+')', ret)
            return
        ret = []
        dfs(0, '', ret)
        return ret