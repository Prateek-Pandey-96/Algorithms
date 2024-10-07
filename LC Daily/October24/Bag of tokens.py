# 948. Bag of Tokens
from typing import List
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        # we can go greedy since using any face up just adds one score

        curr = power
        score = 0
        
        n = len(tokens)
        i, j, ans = 0, n-1, 0
        while i<=j:
            if curr >= tokens[i]:
                curr -= tokens[i]
                score += 1
                i += 1
            elif score > 0:
                curr += tokens[j]
                score -= 1
                j -= 1
            else:
                break
            ans = max(ans, score)
        return ans