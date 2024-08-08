# 3243. Shortest Distance After Road Addition Queries I
from collections import deque
from typing import List

class Solution:
    def bfs(self, n, graph) -> int:
        queue = deque()
        visited = [False for i in range(n)]

        queue.append(0)
        visited[0] = True

        level = -1
        while queue:
            size = len(queue)
            level += 1
            for i in range(size):
                curr = queue.popleft()
                if curr == n-1:
                    return level
                for child in graph[curr]:
                    if visited[child]:
                        continue
                    visited[child] = True
                    queue.append(child)
        return -1


    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(n)}
        for i in range(n-1):
            graph[i].append(i+1)
        
        result = []
        for u,v in queries:
            graph[u].append(v)
            dist = self.bfs(n, graph)
            result.append(dist)
        
        return result