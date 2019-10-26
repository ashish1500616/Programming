int Solution::solve(vector<vector<int>> &A)
{
    int r = A.size();
    int c = A[0].size();
    if (r == 1 && c == 1)
    {
        return A[0][0];
    }
    int ans = INT_MIN;
    // Suff Column
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = c - 1; j >= 0; j--)
        {
            A[i][j] += A[i + 1][j];
        }
    }
    // Suff row
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 2; j >= 0; j--)
        {
            A[i][j] += A[i][j + 1];
        }
    }
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 1; j >= 0; j--)
        {
            ans = max(ans, A[i][j]);
        }
    }

    return ans;
}
