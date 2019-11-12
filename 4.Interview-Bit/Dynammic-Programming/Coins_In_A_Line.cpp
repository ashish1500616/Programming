int mc(vector<vector<int>> &dp, vector<int> &A, int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int pi = A[i] + min(mc(dp, A, i + 1, j - 1), mc(dp, A, i + 2, j));
    int pj = A[j] + min(mc(dp, A, i + 1, j - 1), mc(dp, A, i, j - 2));
    dp[i][j] = max(pi, pj);
    return dp[i][j];
}
int Solution::maxcoin(vector<int> &A)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, -1));
    return mc(dp, A, 0, A.size() - 1);
}
