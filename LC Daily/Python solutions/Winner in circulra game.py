# 1823. Find the Winner of the Circular Game
from collections import deque
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        queue = deque()
        for i in range(n):
            queue.append(i+1)
        
        while len(queue)!=1:
            freq = k
            while freq!=0:
                front = queue.popleft()
                if freq!=1:
                    queue.append(front)
                freq -= 1
            
        return queue.popleft()

