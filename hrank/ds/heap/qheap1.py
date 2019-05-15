
arr = []
length = len(arr)

def percolateDown(first):
    global arr,length
    last=length
    left=2*first+1
    right=2*first+2
    smallest=first
    if(left < last ) and (arr[left] < arr[first]):
        smallest=left
    if(right<last and arr[right]< arr[smallest]):
        smallest=right
    if smallest != first:
        arr[smallest],arr[first]=arr[first],arr[smallest]
        percolateDown(smallest)

def Min():
    global arr, length
    output = arr[0]
    return output
def deleteV(v):
    global arr, length
    f = arr.index(v)
    arr[f] = arr[length-1]
    arr.pop()
    length=length-1
    percolateDown(f)

def parent(i):
    return (i-1)//2

def insertData(data):
    global length, arr
    arr.append(data)
    length = length+1
    i=length-1
    percolateUp(i)
   

def percolateUp(i):
    global arr
    while(i!=0 and arr[parent(i)] > arr[i]):
        arr[parent(i)] ,arr[i] = arr[i],arr[parent(i)]
        i=parent(i)


def main():
    global arr, length
    q = int(input())
    while(q > 0):
        o = input()
        if(len(o) > 1):
            o, di = map(int, o.split())
        else:
            o = int(o)
        if o == 1:
            print("Array Before ---",*arr)
            insertData(di)
            print("Array After ---",*arr)
            print("\n")
        elif o == 2:
            # print(*arr)
            # print("Array Before ---",*arr)
            deleteV(di)
            print("Array After ---",*arr)
            print("\n")
        elif o == 3:
            print(Min())

        q = q-1


if __name__ == "__main__":
    main()
