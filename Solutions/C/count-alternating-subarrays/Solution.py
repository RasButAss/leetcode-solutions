# https://leetcode.com/problems/count-alternating-subarrays/

class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        ret, cur = 0, 0
        for i in range(len(nums)):
            if i and nums[i] == nums[i-1]:
                cur = 1
            else:
                cur += 1
            ret += cur
        return ret
