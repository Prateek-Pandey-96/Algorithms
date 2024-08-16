# 992. Subarrays with K Different Integers
from typing import List
class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        n = len(nums)
        def getCount(K):
            i, j = 0, 0
            hashmap = {}
            count = 0
            while j < n:
                if nums[j] in hashmap:
                    hashmap[nums[j]] += 1
                else:
                    hashmap[nums[j]] = 1
                
                while len(hashmap)>K:
                    hashmap[nums[i]] -= 1
                    if hashmap[nums[i]] == 0:
                        del hashmap[nums[i]]
                    i += 1
                count += j-i+1
                j += 1
            return count

        return getCount(k)-getCount(k-1)