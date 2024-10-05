# 567. Permutation in String
from collections import defaultdict
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)
        if m > n:
            return False
        
        freq = defaultdict(int)
        for ch in s1:
            freq[ch] += 1

        matches = 0
        curr = defaultdict(int)
        for i in range(m):
            curr[s2[i]] += 1
            if curr[s2[i]] == freq[s2[i]]:
                matches += 1
        
        matches = 0
        for i in range(26):
            if curr[chr(i+ord('a'))] == freq[chr(i+ord('a'))]:
                matches += 1
        if matches == 26:
            return True

        for i in range(m, n):
            curr_char, prev_char = s2[i], s2[i-m]
            
            curr[curr_char] += 1
            if curr[curr_char] == freq[curr_char] + 1:
                matches -= 1
            elif curr[curr_char] == freq[curr_char]:
                matches += 1
            
            curr[prev_char] -= 1
            if curr[prev_char] == freq[prev_char]-1:
                matches -= 1
            elif curr[prev_char] ==  freq[prev_char]:
                matches += 1
            
            if matches == 26:
                return True
        
        return False


