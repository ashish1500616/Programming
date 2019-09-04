def main():
    n,k=list(map(int,input().split(' ')))
    a=list(map(int,input().split(' ')))
    b=list(map(int,input().split(' ')))
    m=n+k-1
    o=set()
    c=0
    flag=False
    x=y=0
    for v1 in a:
        y=0
        for v2 in b:
            if (v1+v2) not in o:
            	#
                o.add(v1+v2)
                # print(str(x)+" "+str(y) + "--" +str(v1+v2) )
                c+=1
            if(c==m):
                flag=True
                break;
            y+=1
        if(flag):
            break
        x+=1
    for v in o:
        print(v)

if __name__=="__main__":
    main()
