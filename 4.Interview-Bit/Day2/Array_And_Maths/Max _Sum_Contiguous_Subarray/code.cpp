int Solution::maxSubArray(const vector<int> &A) {
    int cur_sum=0,max_sum=INT_MIN;
    int size=int(A.size());
    int i=0;
    while(i<size)
    {
        cur_sum+=A[i++];
        max_sum=max(max_sum,cur_sum);
        if(cur_sum<0)
        {
            cur_sum=0;
        }
        
    }
    return max_sum;
}