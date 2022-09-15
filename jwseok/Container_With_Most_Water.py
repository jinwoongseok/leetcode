class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        res = 0
        while left < right:
            w = right - left
            h = min(height[right], height[left])
            res = max(res, w*h)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        return res
