# 1052. Grumpy Bookstore Owner
from typing import List
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        total_customers = 0
        for idx in range(len(grumpy)):
            if grumpy[idx]==0:
                total_customers += customers[idx]

        extra_customers = 0
        for idx in range(minutes):
            if grumpy[idx]==1:
                extra_customers += customers[idx]

        ans = total_customers + extra_customers

        for idx in range(minutes, len(grumpy)):
            if grumpy[idx]==1:
                extra_customers += customers[idx]
            if grumpy[idx-minutes]==1:
                extra_customers -= customers[idx-minutes]
            ans = max(ans, total_customers+extra_customers)

        return ans
            
        