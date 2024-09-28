# 641. Design Circular Deque

class Node:
    
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None
    
class MyCircularDeque:

    def __init__(self, k: int):
        self.head, self.tail = Node(-1), Node(-1)
        self.curr_size, self.limit = 0, k
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        front_neighbour = self.head.next
        newnode = Node(value)

        self.head.next = newnode
        newnode.prev = self.head
        
        newnode.next = front_neighbour
        front_neighbour.prev = newnode
        
        self.curr_size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        last_neighbour = self.tail.prev
        newnode = Node(value)

        self.tail.prev = newnode
        newnode.next = self.tail
        
        newnode.prev = last_neighbour
        last_neighbour.next = newnode
        
        self.curr_size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        
        second_neighbour = self.head.next.next
        self.head.next = second_neighbour
        second_neighbour.prev = self.head
        self.curr_size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        
        second_neighbour = self.tail.prev.prev
        self.tail.prev = second_neighbour
        second_neighbour.next = self.tail
        self.curr_size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.head.next.val        

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.tail.prev.val
        

    def isEmpty(self) -> bool:
        return self.curr_size == 0

    def isFull(self) -> bool:
        return self.curr_size == self.limit


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()