class Heap(object):
    def __init__(self):
        self.heapList = [0]
        self.size = 0

    def parent(self, index):
        return index // 2

    def leftChildren(self, index):
        return 2 * index + 1

    def rightChildren(self, index):
        return 2 * index

    def getMaximum(self):
        if self.size == 0:
            return -1
        return self.heapList[0]

    def getMinimum(self):
        if self.size == 0:
            return -1
        return self.heapList[0]

    def xorSwap(a, b):
        a = a ^ b
        b = b ^ a
        a = a ^ b

    def percolateDown(self, i):
        while (i * 2) <= self.size:
            minimumChild = self.minChild(i)
            if self.heapList[i] > self.heapList[minimumChild]:
                # a=a^b   , b=a^b^b a=a^b^a (XOR Swapping)
                self.heapList[i] = self.heapList[i] ^ self.heapList[minimumChild]
                self.heapList[minimumChild] = self.heapList[i] ^ self.heapList[minimumChild]
                self.heapList[i] = self.heapList[i] ^ self.heapList[minimumChild]
            i = minimumChild

    def minChild(self, i):
        # Condition to check if a node is having only one child.
        if i * 2 + 1 > self.size:
            return i * 2
        else:
            # if both the child is present find the minimum of the two.
            if self.heapList[i * 2] < self.heapList[i * 2 + 1]:
                return i * 2
            else:
                return i * 2 + 1

    def percolateUp(self, i):
        while i // 2 > 0:
            if self.heapList[i] < self.heapList[i // 2]:
                self.heapList[i //
                              2] = self.heapList[i] ^ self.heapList[i // 2]
                self.heapList[i] = self.heapList[i] ^ self.heapList[i // 2]
                self.heapList[i //
                              2] = self.heapList[i] ^ self.heapList[i // 2]
            i = i // 2

    # Delete Maximum For MaxHeap
    def deleteMax(self):
        retVal = self.heapList[1]
        self.heapList[1] = self.heapList[self.size]
        self.size = self.size - 1
        self.heapList.pop()
        self.percolateDown(1)
        return retVal
    # Time Complexity = O(log n)

    # Delete Minimum for MinHeap
    def deleteMin(self):
        retVal = self.heapList[1]
        self.heapList[1] = self.heapList[self.size]
        self.size = self.size - 1
        self.heapList.pop()
        self.percolateDown(1)
        return retVal
    # Time Complexity = O(log n)

    def insert(self, k):
        self.heapList.append(k)
        self.size = self.size + 1
        self.percolateUp(self.size)
    # Time Complexity = O(log n)

    def buildHeap(self, A):
        i = len(A) // 2
        self.size = len(A)
        self.heapList = [0] + A[:]
        while(i > 0):
            self.percolateDown(i)
            i = i - 1


obj = Heap()
obj.insert(10)
obj.insert(8)
obj.insert(7)
obj.insert(90)
obj.insert(80)
obj.insert(50)
obj.buildHeap(obj.heapList)
obj.deleteMin()
obj.buildHeap(obj.heapList)
for i in a:
    if i != 0:
        print(i)
