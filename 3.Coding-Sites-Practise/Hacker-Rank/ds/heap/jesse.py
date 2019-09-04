
def percolateDown(arr,i):
    l=len(arr)
    left=2*i+1
    right=2*i+2
    smallest=i
    if(left<l) and (arr[left] < arr[i] ):
        smallest=left
    if(right<l) and (arr[right]<arr[smallest]):
        smallest=right
    if(smallest!=i):
        arr[smallest],arr[i]=arr[i],arr[smallest]
        percolateDown(arr,smallest)

def parent(i):
    return (i-1)//2

def percolateUp(arr):
    l=len(arr)
    i=(l-1)
    while(i!=0) and (arr[parent(i)]>arr[i]):
        arr[parent(i)],arr[i] = arr[i],arr[parent(i)]
        i=parent(i)

def build_heap(arr):
    length=len(arr)
    leastparent=(length-2)//2
    for i in range(leastparent,-1,-1):
        percolateDown(arr,i,length)

def getMin(arr):
    length=len(arr)
    retval=arr[0]
    arr[0]=arr[length-1]
    arr.pop()
    percolateDown(arr,0)
    return retval

def insert(arr,data):
    arr.append(data)
    length=len(arr)
    percolateUp(arr)

def main():
    n , k =map(int,input().split())
    arr=list(map(int,input().split()))
    heap_arr=[]
    count=0
    for x in arr:
        insert(heap_arr,x)
    # print(*heap_arr)
    # while ((all([x >= k for x in heap_arr]))== False):
    status =True
    while(1):
        if(len(heap_arr)==0):
            status=False
            break
        min1=getMin(heap_arr)
        if(min1>=k):
            break
        if(len(heap_arr)==0):
            if min1 < k:
                status=False
            break
        # print("Value Of Min",min1,status)
        min2=getMin(heap_arr)
        # print(min2)
        val=min1+2*min2
        # print(val)
        insert(heap_arr,val)
        count+=1
        # print(status)
    if status:
        print(count)
    else:
        print(-1)



if __name__=="__main__":
    main()

