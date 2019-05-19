# cook your dish here

#Code to Percolate Down For Max _ heap
def percolateDown(arr, first):
    left=2*first+1
    right=2*first+2
    largest=first
    last=len(arr)
    if(left<last) and (arr[left][1] > arr[largest][1]):
        largest=left
    if(right<last) and (arr[right][1]>arr[largest][1]):
        largest=right
    if(largest!=first):
        arr[largest],arr[first]=arr[first],arr[largest]
        percolateDown(arr,largest)

def parent(index):
    return (index-1)//2
def percolateUp(arr,index):
    while (index!=0)  and (arr[parent(index)][1] < arr[index][1]):
        arr[parent(index)], arr[index] =arr[index],arr[parent(index)]
        index=parent(index)

def insertHeap(arr,data):
    arr.append(data)
    length=len(arr)-1
    percolateUp(arr,length)

def getMax(arr):
    retval =arr[0]
    length=len(arr)-1
    arr[0]=arr[length]
    arr.pop()
    percolateDown(arr,0)
    return retval

def main():
    
    q=int(input())
    while(q>0):
        heap_arr=[]
        n,d=map(int,input().split())
        na={}
        while(n>0):
            td=[0]*2
            ip1,td[0],td[1]=map(int,input().split())
            ip1=str(ip1)
            if ip1 not in na:
                na[ip1]=[]
            na[ip1].append(td)
            n-=1
        ij=1
        while(ij<=d):
            tij=str(ij)
            if (tij in na) and (len(na[tij])>0):
                for v in na[tij]:
                    insertHeap(heap_arr,v)
            if(len(heap_arr)>0):
                val = getMax(heap_arr)
                # print(val)
                val[0]-=1
                if(val[0]>0):
                    insertHeap(heap_arr,val)            
            ij+=1
        sum=0
        for item in heap_arr:
            sum=sum+item[0]*item[1]
        print(sum)
        
        q-=1

if __name__=="__main__":
    main()