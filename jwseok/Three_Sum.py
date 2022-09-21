class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        hashMap = {}
        nums.sort()
        answer = set()
        for idx, value in enumerate(nums):
            hashMap[value] = idx

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                target = -1 * (nums[i] + nums[j])
                if target in hashMap and hashMap[target] > j:
                    answer.add((nums[i], nums[j], target))
        return answer