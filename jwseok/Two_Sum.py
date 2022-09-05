class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            tmp = target - nums[i]
            if tmp in hashmap:
                return [i, hashmap[tmp]]
            hashmap[nums[i]] = i