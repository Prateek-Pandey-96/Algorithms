# 2045. Second Minimum Time to Reach Destination
from typing import List
class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        """ 
            modified bfs instead of a set use a map to count
            visits as each node can be visited twice 
        """
        # form graph
        graph = {i:[] for i in range(n)}
        for u, v in edges:
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
        
        # form queue and hashmap
        queue = deque()
        t1 = [float("inf")] * n
        t2 = [float("inf")] * n
        
        queue.append((0, 0))
        t1[0] = 0

        # do BFS
        while queue:
            src, leaving_time = queue.popleft()

            if (leaving_time//change)%2 != 0:
                leaving_time = leaving_time + change - leaving_time%change
            leaving_time += time
            
            for child in graph[src]:
                if leaving_time < t1[child]:
                    queue.append((child, leaving_time))
                    t2[child] = t1[child]
                    t1[child] = leaving_time
                elif leaving_time > t1[child] and leaving_time < t2[child]:
                    queue.append((child, leaving_time))
                    t2[child] = leaving_time

        # return result
        return t2[n-1] if t2[n-1] != float("inf") else -1


