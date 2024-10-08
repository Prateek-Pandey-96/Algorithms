# 1963. Minimum Number of Swaps to Make the String Balanced
class Solution:
    def minSwaps(self, s: str) -> int:
        n = len(s)
        i, j = 0, n-1

        open = 0
        count = 0
        while i < j:
            if s[i] == '[':
                open += 1
            else:
                open -= 1

            if open<0:
                while s[j] != '[':
                    j -= 1
                count += 1
                open = 1
            i += 1
        
        return count