class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        hash_map = {}
        answer = []
        for i, num in enumerate(nums):
            hash_map[num] = i
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    tmp = -(nums[i] + nums[j] + nums[k] - target)
                    if tmp in hash_map and hash_map[tmp] > k:
                        answer.append((nums[i],nums[j],nums[k],tmp))
        answer = set(answer)
        return answer