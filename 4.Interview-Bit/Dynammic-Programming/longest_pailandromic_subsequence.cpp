int Solution::solve(string A)
{
    int n = A.size();
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
        M[i][i] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; (j + i) < A.size(); j++)
        {
            // If A[i] == A[j] is equal add 2 + sum of Longest Palindromic Subsequence  A[i+1:j-1]
            if (A[j] == A[j + i])
                M[j][j + i] = 2 + M[j + 1][j + i - 1];
            else // If Not Find Max of A[i:j-1] and A[i+1:j]
                M[j][j + i] = max(M[j][j + i - 1], M[j + 1][j + i]);
        }
    }
    return M[0][n - 1];
}
