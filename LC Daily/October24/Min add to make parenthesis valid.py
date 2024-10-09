class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        count: int = 0
        open: int = 0
        for ch in s:
            if ch=='(':
                open += 1
            else:
                open -= 1
            
            if open < 0:
                open = 0
                count += 1
            
        return count + open