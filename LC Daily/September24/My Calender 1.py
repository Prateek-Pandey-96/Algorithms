# 729. My Calendar I
class Tree:
    def __init__(self, start, end) -> None:
        self.left = None
        self.right = None
        self.start = start
        self.end = end
    
    def insert(self, start, end) -> bool:
        curr = self
        while True:
            if end <= curr.start:
                if not curr.left:
                    curr.left = Tree(start, end)
                    return True
                curr = curr.left
            elif start >= curr.end:
                if not curr.right:
                    curr.right = Tree(start, end)
                    return True
                curr = curr.right
            else:
                return False

class MyCalendar:
    def __init__(self):
        self.root = None

    def book(self, start: int, end: int) -> bool:
        if not self.root:
            self.root = Tree(start, end)
            return True
        return self.root.insert(start, end)
