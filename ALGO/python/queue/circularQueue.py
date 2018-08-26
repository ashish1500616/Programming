class Queue(object):
    # Constructor of Class Queue
    def __init__(self, limit=5):
        self.que = []
        self.limit = limit
        self.front = None
        self.rear = None
        self.size = 0

    # Function to check if queue is empty
    def isEmpty(self):
        return self.size <= 0

    # Function to insert an element into the circular queue
    def enQueue(self, item):
        if self.size >= self.limit:
            print("Queue OverFlow!")
            return
        else:
            self.que.append(item)

        if self.front is None:
            self.front = self.rear = 0
        else:
            self.rear = self.size
        self.size += 1

        print("Queue After Enqueue", self.que)

    # Function to Dequeue element from the front
    def deQueue(self):
        if self.size <= 0:
            print("Queue Undeflow!")
            return 0
        else:
            self.que.pop(0)
            self.size -= 1
            if self.size == 0:
                self.front = self.rear = None
            else:
                self.rear = self.size - 1

            print("Queue after Dequeue", self.que)

    # Function to return element from the rear
    def queueRear(self):
        if self.rear is None:
            print("This Queue is Empty!")
            raise IndexError
        return self.que[self.rear]

    # Function to return element from the front
    def queueFront(self):
        if self.front is None:
            print("This Queue Is Empty!")
            raise IndexError
        return self.que[self.front]

    # Function to return the size of the array
    def size(self):
        return self.size


#
# def main():
print("Inside Main")
que = Queue()
que.enQueue("First")
print(que.queueFront())
que.enQueue("Second")
que.enQueue("5")
que.deQueue()
print(que.que)
print(que.queueRear())
print(que.queueFront())
print(que.size)
que.enQueue(4)
que.enQueue(6)
que.enQueue(7)
que.deQueue()
que.enQueue(8)
print(que.queueFront())
print(que.queueRear())
# if __name__ == "main":
#     main()
