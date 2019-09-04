# Modified percolateDown
def percolateDown(A, first, last):
    largest = 2 * first + 1
    while largest <= last:
        # right child exist and is larger than left minChild
        if(largest < last) and (A[largest] < A[largest + 1]):
            largest += 1
        # right child is larger than parent
        if A[largest] > A[first]:
            swap(A, largest, first)
            # move down to largest minChild
            first = largest
            largest = 2 * first + 1
        else:
            return


def swap(A, x, y):
    # temp = A[x]
    # A[x] = A[y]
    # A[y] = temp
    A[x]=A[x]^A[y]
    A[y]=A[y]^A[x]
    A[x]=A[x]^A[y]


def heapSort(A):
    length = len(A) - 1
    leastParent = length // 2
    for i in range(leastParent, -1, -1):
        percolateDown(A, i, length)
    
    print(*A)

    for i in range(length, 0, -1):
        if A[0] > A[i]:
            swap(A, 0, i)
            percolateDown(A, 0, i - 1)

print("Inside HeapSort")
a = [10, 78, 34, 56, 32, 99]
heapSort(a)
for i in a:
    print(i)
print("Exiting HeapSort")
