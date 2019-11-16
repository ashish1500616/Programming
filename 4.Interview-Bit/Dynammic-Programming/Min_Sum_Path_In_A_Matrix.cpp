int find(vector<vector<int>> &dp, vector<vector<int>> &A, int i, int j)
{
    // cout<<A[i][j]<<"-> ";
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == A.size() - 1 && j == int(A[0].size()) - 1)
    {
        return A[i][j];
    }
    int sum = 0;
    if (j + 1 >= A[0].size())
    {
        sum += A[i][j] + find(dp, A, i + 1, j);
    }
    else if (i + 1 >= A.size())
    {
        sum += A[i][j] + find(dp, A, i, j + 1);
    }
    else
    {
        int l = 0, r = 0;
        l += A[i][j] + find(dp, A, i + 1, j);
        r += A[i][j] + find(dp, A, i, j + 1);
        sum += min(l, r);
    }
    dp[i][j] = sum;
    return sum;
}
int Solution::minPathSum(vector<vector<int>> &A)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(A[0].size() + 1, -1));
    int sum = 0;
    sum = find(dp, A, 0, 0);
    return sum;
}
