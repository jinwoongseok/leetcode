class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or len(s) == 1:
            return s
        L = [''] * numRows
        step = 1
        row = 0
        for char in s:
            L[row] += char
            if row == numRows - 1:
                step = -1
            elif row == 0:
                step = 1
            row += step
        return ''.join(L)
