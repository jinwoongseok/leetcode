from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1,-1]
        start = bisect_left(nums, target)
        if start >= len(nums) or nums[start] != target:
            return [-1,-1]
        end = bisect_right(nums, target)
        return [start, end-1]        
