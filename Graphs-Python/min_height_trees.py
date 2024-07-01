# 310. Minimum Height Trees
from typing import List
from collections import deque
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        # at max a graph can have only two min height trees
        if n==1:
            return [0]
        graph: dict[int, List[int]] = {i:[] for i in range(n)}
        degree: List[int] = [0 for i in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
            degree[edge[0]] += 1
            degree[edge[1]] += 1
        
        queue = deque()
        for i in range(n):
            if degree[i] == 1:
                queue.append(i)
        
        nodes = n
        while(nodes > 2):
            size = len(queue)
            while size>0:
                src = queue.popleft()
                degree[src] -= 1
                
                for child in graph[src]:
                    degree[child] -= 1
                    if degree[child] == 1:
                        queue.append(child)
                size -= 1
                nodes -= 1
        
        result = []
        while(len(queue)):
            result.append(queue.popleft())
        
        return result