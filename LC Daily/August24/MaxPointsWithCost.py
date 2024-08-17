# 1937. Maximum Number of Points with Cost
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # seems like a classic dp problem but it is not that straighforward
        m, n = len(points), len(points[0])

        dp = []
        for j in range(n):
            dp.append(points[0][j])

        for i in range(1, m):
            left, right = [0]*n, [0]*n
            left[0], right[n-1] = dp[0], dp[n-1]

            for j in range(1, n):
                left[j] = max(dp[j], left[j-1]-1)
                right[n-1-j] = max(dp[n-1-j], right[n-j]-1)
             
            for j in range(n):
                dp[j] = max(left[j], right[j]) + points[i][j]
        
        result = dp[0]
        for j in range(1, n):
            result = max(result, dp[j])
        
        return result
