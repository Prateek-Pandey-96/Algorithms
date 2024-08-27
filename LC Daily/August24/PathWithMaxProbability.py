# 1514. Path with Maximum Probability
from typing import List
from heapq import heapify, heappush, heappop
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        # form distance vector
        p_vector = [-0.0 for _ in range(n)]
        
        # form graph
        graph = {i:[] for i in range(n)}
        for i in range(len(edges)):
            u, v = edges[i]
            p = succProb[i]
            graph[u].append((v, p))
            graph[v].append((u, p))

        # initialize for dijkstra's   
        heap = [(-1.0, start_node)]
        p_vector[start_node] = -1.0
        heapify(heap)

        # run dijkstra's algorithm
        while heap:
            curr_p, curr_node = heappop(heap)
            if curr_node == end_node:
                p_vector[curr_node] = curr_p
                break

            for child, wt in graph[curr_node]:
                if wt * -curr_p <= -p_vector[child]:
                    continue
                p_vector[child] = wt * curr_p
                heappush(heap, (p_vector[child], child))

        # end node is unreachable
        if p_vector[end_node]==float("-inf"):
            return 0
        
        # return max probability
        return -p_vector[end_node]