int Solution::solve(const string A, const string B)
{
    int ans = 1;
    int n = A.size();
    int j = 0, i;
    if (A == B)
        return 1;
    for (i = 0; i < n; i++)
    {
        if (A[i] != B[j])
            return 0;
        while (A[i] == B[j])
            j++;
    }
    if (j == A.size())
        return 0;
    return 1;
}
