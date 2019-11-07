int Solution::solve(vector<int> &A, vector<int> &B) {
    int now=-1 ;
    // 0 for website & 1 for App.
    int i=0,j=0;
    int nw=A.size();
    int na=B.size();
    if(nw==0 || na == 0)
    {
        return 0;
    }
    int cc=0;
    while(i<nw && j<na)
    {   // TS = App 
        if(B[j] < A[i])
        {
            if(now==-1)
            {
                now=1;
                continue;
            }
            // P = Website 
            if( now == 0)
            {
                ++cc;
                now=1;
            }
            j++;
        }
        else
        {
            if(now==-1)
            {
                now=0;
                continue;
            }
            // TS = Web
            // P = App 
            if(now == 1)
            {
                ++cc;
                now=0;
            }
            ++i;
        }
    }
    if(i<nw || j<na)
    {
        cc+=1;
    }
    return cc;
}
