# 2191. Sort the Jumbled Numbers
from typing import List
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        helper = []
        for i in range(len(nums)):
            original = nums[i]
            num = str(nums[i])
            mapped_value = ""
            for char in num:
                mapped_value += str(mapping[int(char)])
            helper.append((original, int(mapped_value), i))
        helper = sorted(helper, key=lambda x: (x[1], x[2]))
        result = []
        for tup in helper:
            result.append(tup[0])
        return result