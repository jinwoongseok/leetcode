class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        self.letters = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }
        self.digits = digits
        self.answer = []
        self.digits_len = len(digits)
        self.dfs(0, '')
        return self.answer

    def dfs(self, depth, ret):
        if depth == self.digits_len:
            self.answer.append(ret)
            return
        num = self.digits[depth]
        candidate = self.letters[num]
        for char in candidate:
            ret += char
            self.dfs(depth+1, ret)
            ret = ret[:-1]
        return
