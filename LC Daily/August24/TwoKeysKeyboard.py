# 650. 2 Keys Keyboard

class Solution:
    def minSteps(self, n: int) -> int:
        dp = [float("inf") for _ in range(n+1)]
        dp[1] = 0
        for i in range(2, n+1):
            dp[i] = i
            for j in range(1, i):
                if i%j == 0:
                    # 1 copy i//j - 1 paste
                    dp[i] = min(dp[i], dp[j] + 1 + (i//j - 1))
        
        return dp[n]