from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate: int = -1
        count: int = 0

        for num in nums:
            if count == 0:
                candidate = num
                count += 1
            else:
                if num == candidate:
                    count += 1
                else:
                    count -=1

        # not required as a majority element is guaranteed
        # count_candidate = 0
        # for num in nums:
        #     if num == candidate:
        #         count_candidate += 1
        
        return candidate
