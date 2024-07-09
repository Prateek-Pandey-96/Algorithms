# 1701. Average Waiting Time
from typing import List
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        end_time = 0
        wait_time = 0
        
        for customer in customers:
            if customer[0]>=end_time:
                wait_time += customer[1]
                end_time = customer[0]+customer[1]
            else:
                wait_time += customer[1] + end_time - customer[0]
                end_time = end_time+customer[1]

        return wait_time/len(customers)