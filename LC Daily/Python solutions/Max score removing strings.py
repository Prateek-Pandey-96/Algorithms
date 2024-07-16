# 1717. Maximum Score From Removing Substrings

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        # seems to be 1-d DP wrong approach as we are not considering previous string again
        # n = len(s)
        # @cache
        # def DFS(i):
        #     if i >= n-1:
        #         return 0

        #     if s[i]=='a' and s[i+1]=='b':
        #         return max(x + DFS(i+2), DFS(i+1))
        #     if s[i]=='b' and s[i+1]=='a':
        #         return max(y + DFS(i+2), DFS(i+1))

        #     return DFS(i+1)   
        
        # return DFS(0)

        # Correct approach greedy two traversals
        def get_score(ab: bool) -> int:
            curr = 'b' if ab else 'a'
            prev = 'a' if ab else 'b'
            larger = x if ab else y
            smaller = y if ab else x
            ls = []
            score, i, n = 0, 0, len(s)
            while i < n:
                if len(ls)!=0 and s[i]==curr and ls[-1]==prev:
                    score += larger
                    ls.pop()
                else:
                    ls.append(s[i])
                i += 1
            n, i = len(ls), 0
            ls_temp = []
            while i < n:
                if len(ls_temp)!=0 and ls[i]==prev and ls_temp[-1]==curr:
                    score += smaller
                    ls_temp.pop()
                else:
                    ls_temp.append(ls[i])
                i += 1
            return score
        
        ab = True if x>=y else False
        return get_score(ab)
            
            
 