# 912. Sort an Array
from typing import List
class Solution:

    def merge2sortedArrays(self, left, right):
        i, j, k = 0, 0, 0
        m, n = len(left), len(right)
        result = [0 for i in range(m+n)]

        while i < m and j < n:
            if left[i] < right[j]:
                result[k] = left[i]
                k += 1
                i += 1
            else:
                result[k] = right[j]
                k += 1
                j += 1

        while i < m:
            result[k] = left[i]
            k += 1
            i += 1
        
        while j < n:
            result[k] = right[j]
            k += 1
            j += 1   

        return result         

    def mergeSort(self, nums, low, high):
        if low > high:
            return []
        if low == high:
            return [nums[low]]
        
        mid = low + (high - low)//2
        left = self.mergeSort(nums, low, mid)
        right = self.mergeSort(nums, mid+1, high)
        return self.merge2sortedArrays(left, right)

    def sortArray(self, nums: List[int]) -> List[int]:
        return self.mergeSort(nums, 0, len(nums)-1)