class Solution:
    def reverse(self, x: int) -> int:
        str_x = str(x)
        if str_x[0] == '-':
            rev_str_x = str_x[::-1]
            rev_str_x = rev_str_x[:-1]
            rev_x = int(rev_str_x)
            rev_x = -rev_x
        else:
            rev_str_x = str_x[::-1]
            rev_x = int(rev_str_x)
        if rev_x >= -2**31 and rev_x <= 2**31-1:
            return rev_x
        return 0

    def awesome(self, x: int) -> int:
        sign = 1 if x >= 0 else -1
        result = sign * int(str(abs(x))[::-1])
        if result >= -2**31 and result <= 2**31-1:
            return result
        return 0
