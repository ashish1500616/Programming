bool isP(string &A, int i, int j)
{
    while (i <= j)
        if (A[i++] != A[j--])
        {
            return false;
        }
    return true;
}
int mC(vector<vector<int>> &dp, string &A, int s, int e)
{
    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }
    if (s >= e || isP(A, s, e))
    {
        return 0;
    }
    int mc = e - s;
    for (int i = s; i < e; i++)
    {
        if (isP(A, s, i))
        {
            mc = min(mc, 1 + mC(dp, A, i + 1, e));
        }
    }
    dp[s][e] = mc;
    return mc;
}
int Solution::minCut(string A)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, -1));
    return mC(dp, A, 0, A.size() - 1);
}
