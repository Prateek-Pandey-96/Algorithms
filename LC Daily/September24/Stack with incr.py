# 1381. Design a Stack With Increment Operation 
class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.incr = []
        self.limit = maxSize

    def push(self, x: int) -> None:
        if len(self.stack) == self.limit:
            return
        self.stack.append(x)
        self.incr.append(0) 

    def pop(self) -> int:
        if len(self.stack) == 0:
            return -1
        element = self.stack.pop()
        increase = self.incr.pop()
        if len(self.stack) > 0:
            self.incr[-1] += increase
        return element + increase

    def increment(self, k: int, val: int) -> None:
        k -= 1
        if k < 0:
            return
        
        if k >= len(self.stack):
            k = len(self.stack)-1
        
        if len(self.stack) > 0:
            self.incr[k] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)