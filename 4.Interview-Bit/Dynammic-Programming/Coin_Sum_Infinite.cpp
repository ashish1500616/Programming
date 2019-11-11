
#define MOD 1000007
int Solution::coinchange2(vector<int> &A, int B)
{
    vector<vector<int>> dp(A.size(), vector<int>(B + 1, 0));
    for (int i = 0; i < A.size(); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= B; i++)
    {
        if (i % A[0] == 0)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j <= B; j++)
        {
            if (j >= A[i])
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - A[i]]) % MOD;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j]) % MOD;
            }
        }
    }
    return dp[A.size() - 1][B];
} //  Memory Limit Exceeds.
