class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            if dp[i-1] == i-1:
                break
            dp[i] = max(dp[i-1], i+nums[i])
        if dp[len(nums)-1] == 0:
            return False
        return True