# 2092. Find All People With Secret
from typing import List
from collections import defaultdict

class Solution:
    def dfs(self, src, graph, visited, people) -> None:
        visited.add(src)
        people.add(src)

        for child in graph[src]:
            if child not in visited:
                self.dfs(child, graph, visited, people)

    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        people = set([0, firstPerson])
        
        # store meetings by time
        timemap = {}
        for person1, person2, time in meetings:
            if time not in timemap:
                timemap[time] = defaultdict(list)
            timemap[time][person1].append(person2)
            timemap[time][person2].append(person1)
        
        for time, graph in sorted(timemap.items()):
            visited = set()
            for key in graph.keys():
                if key in people:
                    self.dfs(key, graph, visited, people)

        return list(people)