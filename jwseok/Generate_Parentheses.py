class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []
        def generate(cur = []):
            if len(cur) == 2*n:
                if valid(cur):
                    answer.append(''.join(cur))
                return
            cur.append('(')
            generate(cur)
            cur.pop()
            cur.append(')')
            generate(cur)
            cur.pop()
            
        def valid(parentheses = []):
            cnt = 0
            for char in parentheses:
                if char == '(':
                    cnt += 1
                else:
                    cnt -= 1
                if cnt < 0:
                    return False
            if cnt != 0:
                return False
            return True
        generate([])
        return answer