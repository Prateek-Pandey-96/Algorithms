# 1653. Minimum Deletions to Make String Balanced

class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        pre, post = [0]*n, [0]*n

        # find 'b' before an idx
        countb = 0
        for i in range(n):
            pre[i] = countb
            if s[i]=='b':
                countb += 1

        # find 'a' after an idx
        counta = 0
        for i in range(n-1, -1, -1):
            post[i] = counta
            if s[i]=='a':
                counta += 1   

        # treat every point as answer from 0 to n-1
        ans = float("inf")
        for i in range(n):
            b_before = pre[i]
            a_after = post[i]
            ans = min(ans, b_before + a_after)

        return ans
