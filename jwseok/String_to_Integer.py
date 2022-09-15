class Solution:
    def myAtoi(self, s: str) -> int:
        mstr = s.lstrip()
        sign = 1
        MAX_NUM = 2**31 - 1
        MIN_NUM = -2**31
        if len(mstr) == 0:
            return 0

        if mstr[0] == '-':
            sign = -1
            mstr = mstr[1:]
        elif mstr[0] == '+':
            mstr = mstr[1:]

        new_str = ''
        for char in mstr:
            if char >= '0' and char <= '9':
                new_str += char
            else:
                break
        if len(new_str) == 0:
            return 0
        result = sign * int(new_str)
        return max(MIN_NUM, min(result, MAX_NUM))