def main():
    q=int(input())
    
    while(q>0):
        nt,nd=map(int,input().split())
        ns=[]
        while(nt>0):
            dic=[0,0,0]
            dic[0],dic[1],dic[2]=map(int,input().split())
            ns.append(dic)
            nt-=1
        jv=1
        while(jv<=nd):
            m=0
            val=100000
            for i,x in enumerate(ns):
                if x[1]!=0 and x[0]<=jv:
                    if x[0]<val :
                        m=i
                        val=x[0]
                    elif x[0]==val:
                        if x[2] < ns[m][2]:
                            m=i
            if ns[m][0]<=jv:
                ns[m][1]-=1
            jv+=1
        
        
        sum=0
        for x in ns:
            if x[1]>=0:
                sum+=x[1]*x[2]
        print(sum)
        q-=1

main()