class Solution:
    # @param A : string
    # @return a strings
    def solve(self, A):
        c = 0
        n = len(A)
        if(n & 1):
            i = n//2+1
            j = n//2-1
        else:
            i = n//2
            j = i-1
        while(i < n and j >= 0):
            # print(j," ",i)
            if(A[i] != A[j]):
                c += 1
            i += 1
            j -= 1
        if c == 0 and n & 1:
            return "YES"
        elif c == 1:
            return "YES"
        else:
            return "NO"
