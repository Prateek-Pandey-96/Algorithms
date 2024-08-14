# 719. Find K-th Smallest Pair Distance 
from typing import List
class Solution:
    def find_subarrays(self, nums, max_diff):
        count = 0
        for i in range(len(nums)):
            low, high = i, len(nums)-1
            idx = i
            while low <= high:
                mid = low + (high-low)//2
                if nums[mid]-nums[i] > max_diff:
                    high = mid-1
                else:
                    idx = mid
                    low = mid+1
            count += idx-i
        return count
    
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort(nums)
        low, high = 0, nums[-1] - nums[0]
        result = 0
        while low <= high:
            max_diff = low + (high-low)//2
            subarrays = self.find_subarrays(nums, max_diff)

            if subarrays < k:
                low = max_diff + 1 
            elif subarrays >= k:
                result = max_diff
                high = max_diff-1
        
        return result


