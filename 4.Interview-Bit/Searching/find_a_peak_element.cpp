int findPeak(vector<int> &A, int l, int h, int n)
{
    int m = l + (h - l) / 2;
    if ((m == 0 || A[m] >= A[m - 1]) && (m == n - 1 || A[m + 1] <= A[m]))
    {
        return A[m];
    }
    else if (m > 0 && A[m - 1] > A[m])
    {
        return findPeak(A, l, m - 1, n);
    }
    else
    {
        return findPeak(A, m + 1, h, n);
    }
}
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int ans = findPeak(A, 0, n - 1, n);
    return ans;
}
