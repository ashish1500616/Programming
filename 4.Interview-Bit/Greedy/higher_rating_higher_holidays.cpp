int Solution::solve(vector<int> &A)
{
    int n = A.size();
    vector<int> cs(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i + 1] > A[i])
            cs[i + 1] = cs[i] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
            cs[i] = cs[i + 1] + 1;
    }
    return accumulate(cs.begin(), cs.end(), 0);
}
