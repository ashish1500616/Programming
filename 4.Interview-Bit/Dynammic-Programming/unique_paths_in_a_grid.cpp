int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    if (A[A.size() - 1][A[0].size() - 1] == 1 || A[0][0] == 1)
    {
        return 0;
    }
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    if (A[0][0] == 0)
    {
        dp[0][0] = 1;
    }
    else
    {
        dp[0][0] = 0;
    }
    for (int i = 1; i < A[0].size(); i++)
    {
        if (A[0][i - 1] != 1 && A[0][i] == 0)
            dp[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1][0] != 1 && A[i][0] == 0)
            dp[i][0] = 1;
        else
            break;
    }
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < A[0].size(); j++)
        {
            if (A[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    // for(auto x:dp)
    // {
    //     for(auto y:x)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<"\n";
    // }
    return dp[A.size() - 1][A[0].size() - 1];
}

// Keep A Track of first row and column......... .
// cases : 0 0 0 0 1 0 0
// cases : 1 0
// cases : 0 1
// cases :  1  0
// 0  0
// 0  1
// 0  0
// 0  0