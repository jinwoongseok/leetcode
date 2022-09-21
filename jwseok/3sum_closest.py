class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # optimization
        if len(nums) < 3:
            return
        nums.sort()
        answer = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            # !!!optimization!!!
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j, k = i+1, len(nums)-1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total == target:
                    return total
                if abs(total-target) < abs(answer-target):
                    answer = total
                if total < target:
                    j += 1
                else:
                    k -= 1

        return answer