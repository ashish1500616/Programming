int Solution::maxArr(vector<int> &A) {
    int size=int(A.size());
    int maxf[2]={INT_MIN,INT_MIN};
    int mins[2]={INT_MAX,INT_MAX};
    int s=INT_MIN;
    for(int i=0;i<size;i++)
    {
        maxf[0]=max(maxf[0],A[i]+i);
        maxf[1]=max(maxf[1],A[i]-i);
        mins[0]=min(mins[0],A[i]+i);
        mins[1]=min(mins[1],A[i]-i);
    }
 
    s=max(maxf[0]-mins[0],maxf[1]-mins[1]);
    return s;
}