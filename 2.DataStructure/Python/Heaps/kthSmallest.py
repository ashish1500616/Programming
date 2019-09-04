class Heap(object):
    self.heapList = []
    self.size = 0

    def __init__(self, A):
        self.heapList = list(A)
        self.size = len(self.heapList)

    def parent(self, i):
        return i//2

    def lchild(self, i):
        return 2*i+1

    def rchild(self, i):
        return 2*i + 2

    def swap(self, a, b):
        a = a ^ b
        b = b ^ a
        a = a ^ b

    