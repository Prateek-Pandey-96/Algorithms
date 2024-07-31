# 1105. Filling Bookcase Shelves
from typing import List
from functools import lru_cache
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        @lru_cache(None)
        def dfs(idx, w_left, h_max): 
            if idx == len(books):
                return h_max
            
            w, h = books[idx]
            
            # Option 1: Place the book on a new row.
            option1 = h_max + dfs(idx + 1, shelfWidth - w, h)
            
            # Option 2: Place the book on the current row, if it fits.
            option2 = float('inf')
            if w <= w_left:
                option2 = dfs(idx + 1, w_left - w, max(h, h_max))
            
            return min(option1, option2)

        return dfs(0, shelfWidth, 0)