int minNumbers(vector<int> &A, int index, int sum)
{
    if (sum == 0)
    {
        return 0;
    }
    if (index >= A.size())
    {
        return INT_MAX;
    }
    int l = INT_MAX;
    if ((A[index] * A[index]) <= sum)
    {
        l = minNumbers(A, index, sum - (A[index] * A[index]));
        if (l != INT_MAX)
        {
            l += 1;
        }
    }
    int r = minNumbers(A, index + 1, sum);
    int ans = min(l, r);
    if (l == INT_MAX && r == INT_MAX)
    {
        return INT_MAX;
    }
    return ans;
}
//  Mohit
int minNumbers(int s, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int x = s * s;
    int l = INT_MAX;
    if (x <= n)
    {
        l = minNumbers(s, n - x) + 1;
    }
    int r = minNumbers(s - 1, n);
    return min(l, r);
}
int Solution::countMinSquares(int A)
{
    // vector<int> candidate;
    // for(int i=1;i<=(A/2);i++)
    // {
    //     candidate.push_back(i);
    // }
    // int ans=0;
    // ans=minNumbers(candidate,0,A);
    // Implementation using 2D DP.
    // vector< vector<int> > dp((A/2)+1,vector<int> (A+1,INT_MAX));
    // for(int i=0;i<=A/2;i++)
    // {
    //     dp[i][1]=1;
    // }
    // for(int i=0;i<=A/2;i++)
    // {
    //     dp[i][0]=0;
    // }
    // for(int i=0;i<=A;i++)
    // {
    //     dp[0][i]=0;
    //     dp[1][i]=i;
    // }
    // for(int i=2;i<=A/2;i++)
    // {
    //     for(int j=1;j<=A;j++)
    //     {
    //         if(j>=i*i)
    //         {
    //             dp[i][j]=min(dp[i-1][j],1+dp[i][j-(i*i)]);
    //         }
    //         else
    //         {
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // for(auto x: dp)
    // {
    //     for(auto y:x)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<dp[A/2][A]<<"\n";

    // vector<int > dp(A+1);
    // dp[0]=0;
    // dp[1]=1;
    // dp[2]=2;
    // dp[3]=3;
    // for(int i=4;i<=A;i++)
    // {
    //     dp[i]=i;
    //     for(int x=1;x<=ceil(sqrt(i));x++)
    //     {
    //         if(x*x>i)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             dp[i]=min(dp[i],1+dp[i-(x*x)]);
    //         }
    //     }
    // }
    // return dp[A];
    return minNumbers(sqrt(A), A);
}
