int Solution::jump(vector<int> &A)
{

    // Dynammic Programming Approach - o (N2)
    // int n=A.size();
    // if( n ==1 && A[0]==0)
    // return 0;
    // if(n > 1 && A[0]==0)
    // return -1;
    // vector<int> m_j_a(n,INT_MAX);
    // m_j_a[0]=0;
    // int ans;
    // for(int i=1;i<n;i++)
    // {
    //     // for(int j=0;j<i;j++)
    //     // {
    //     //     if(i<=j+A[j])
    //     //     {
    //     //         m_j_a[i]=min((m_j_a[i]),(m_j_a[j]+1));
    //     //     }
    //     // }
    //     int j=i-1;
    //     while(j>-1 && (j+A[j]<=i))
    //     {
    //         m_j_a[i]=min((m_j_a[i]),(m_j_a[j]+1));
    //         j--;
    //     }
    // }
    // ans=m_j_a[n-1];
    // return ans;

    //  Dynammic Programming -  O(N)
    int n = A.size();
    if (n == 1)
        return 0;
    int ladder = A[0], stairs = A[0], jump = 1;
    for (int i = 1; i < n - 1; i++)
    {
        ladder = max(ladder, i + A[i]);
        stairs--;
        if (stairs < 0)
            return -1;
        if (stairs == 0)
        {
            jump++;
            stairs = ladder - i;
        }
    }
    if (ladder >= n - 1)
        return jump;
    return -1;
}
