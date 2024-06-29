# 2192. All Ancestors of a Node in a Directed Acyclic Graph
from collections import List, deque
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        indegree = [0]*n
        graph = {}
        for i in range(n):
            graph[i] = []
        for edge in edges:
            indegree[edge[1]] += 1
            graph[edge[0]].append(edge[1])

        queue = deque()
        for i in range(n):
            if indegree[i]==0:
                queue.append(i)

        ancestors = {}
        for i in range(n):
            ancestors[i] = set()    
        
        while(len(queue)):
            src = queue.popleft()
            for dest in graph[src]:
                indegree[dest] -= 1
                if indegree[dest]==0:
                    queue.append(dest)
                ancestors[dest].add(src)
                for anc in ancestors[src]:
                    ancestors[dest].add(anc)

        result = []
        for i in range(n):
            result.append(sorted(list(ancestors[i])))
        return result