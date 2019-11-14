int countD(vector<vector<int>> &dp, string A, string B, int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (j == B.size())
        return 1;
    if (i == A.size())
        return 0;
    int t = 0;
    if (B[j] == A[i])
        t += countD(dp, A, B, i + 1, j + 1);
    t += countD(dp, A, B, i + 1, j);
    dp[i][j] = t;
    return t;
}
int Solution::numDistinct(string A, string B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    int ans = 0;
    ans = countD(dp, A, B, 0, 0);
    return ans;
}