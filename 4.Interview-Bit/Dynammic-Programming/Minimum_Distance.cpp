int mD(vector<vector<int>> &dp, string &A, string &B, int i, int j)
{
    // if(i<0 && j<0)
    // {
    //     return 0;
    // }
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (A[i] == B[j])
    {
        ans = mD(dp, A, B, i - 1, j - 1);
    }
    else
    {
        ans = min(1 + mD(dp, A, B, i - 1, j),
                  min(1 + mD(dp, A, B, i, j - 1),
                      1 + mD(dp, A, B, i - 1, j - 1)));
    }
    dp[i][j] = ans;
    return ans;
}

int Solution::minDistance(string A, string B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    return mD(dp, A, B, A.size() - 1, B.size() - 1);
}
