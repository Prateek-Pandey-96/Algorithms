# 2050. Parallel Courses III
from typing import List
from collections import deque

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graph = {i:[] for i in range(n)}
        indegree = [0] * n
        for edge in relations:
            graph[edge[0]-1].append(edge[1]-1)
            indegree[edge[1]-1] += 1

        q = deque()
        maxtime = [0] * n
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
                maxtime[i] = time[i]

        while q:
            src = q.popleft()
            for child in graph[src]:
                maxtime[child] = max(maxtime[child], time[child]+maxtime[src])
                indegree[child] -= 1 
                if indegree[child]==0:
                    q.append(child)         


        return max(maxtime)
