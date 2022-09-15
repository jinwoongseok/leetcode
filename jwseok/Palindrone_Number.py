class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        str_rev_x = str_x[::-1]
        if str_x == str_rev_x:
            return True
        else:
            return False