class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)-1
        while lo < hi:
            mid = int((lo+hi)/2)
            if nums[mid] > nums[hi]:
                lo = mid+1
            else:
                hi = mid
        rot = lo
        l, r = 0, len(nums)-1
        while l <= r:
            mid = int((l+r)/2)
            real_mid = (mid+rot)%len(nums)
            if nums[real_mid] == target:
                return real_mid
            elif nums[real_mid] > target:
                r = mid-1
            else:
                l = mid+1
        return -1