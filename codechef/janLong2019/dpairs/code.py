def main():
    n,k=list(map(int,input().split(' ')))
    a=list((map(int,input().split(' '))))
    b=list(map(int,input().split(' ')))
    m=n+k-1
    la=list(range(n))
    lb=list(range(k))
    ma=max(n,k)
    la=list(zip(a,la))
    lb=list(zip(b,lb))
    la=sorted(la)
    lb=sorted(lb)
    o=set()
    maxy="a"
    if n>k:
        ma=n
        maxy="a"
    else:
        ma=k
        maxy="b"
    for v1 in range(ma):
        if maxy=="a":
            if(lb[0][0]+la[v1][0]) not in o:
                o.add(lb[0][0]+la[v1][0])
                # print(str(lb[0][1])+" "+str(la[v1][1]) + "--" +str(lb[0][0]+la[v1][0]))
                # print("==SUM=="+str(lb[0][0]+la[v1][0]))
        else:
            if(la[0][0]+lb[v1][0]) not in o:
                o.add(la[0][0]+lb[v1][0])
                # print(str(la[0][1])+" "+str(lb[v1][1]) + "--" +str(la[0][0]+lb[v1][0]))
                # print("==SUM=="+str(la[0][0]+lb[v1][0]))
    m-=ma
    j=0
    c=0
    while(True):
        if maxy=="a":
            if(lb[j][0]+la[ma-1][0]) not in o:
                o.add(lb[j][0]+la[ma-1][0])
                c+=1
                # print(str(lb[j][1])+" "+str(la[ma-1][1])+ "--" +str(lb[j][0]+la[m-1][0]))
                # print("==SUM=="+str(lb[j][0]+la[ma-1][0]))
        else:
            if(la[j][0]+lb[ma-1][0]) not in o:
                o.add(la[j][0]+lb[ma-1][0])
                c+=1
                # print(str(la[j][1])+" "+str(lb[ma-1][1])+ "--" +str(la[j][0]+lb[m-1][0]))
                # print("==SUM=="+str(la[j][0]+lb[ma-1][0]))
        j+=1
        if(c==m):
            break


    # print(*o)
    for v in o:
        print(v)
if __name__=="__main__":
    main()
