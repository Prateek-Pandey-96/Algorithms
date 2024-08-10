class Solution:
    def minSwaps(self, nums):
        sorted_nums = sorted(nums)
        rank = {}
        n, swaps = len(nums), 0
        for i in range(n):
            rank[sorted_nums[i]] = i
            
        for i in range(n):
            while rank[nums[i]] != i:
                to_idx = rank[nums[i]]
                nums[i], nums[to_idx] = nums[to_idx], nums[i]
                swaps += 1
        
        return swaps