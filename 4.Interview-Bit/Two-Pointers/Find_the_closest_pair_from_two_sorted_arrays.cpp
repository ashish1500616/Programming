vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int a, b;
    int n = A.size();
    int m = B.size();
    int i = 0, j = m - 1;
    int c = INT_MAX;
    while (i < n && j >= 0)
    {
        int val = abs(A[i] + B[j] - C);
        if (val < c)
        {
            c = val;
            a = i;
            b = j;
        }
        else if (val == c && i == a)
        {
            while (val == abs(A[i] + B[j] - C))
            {
                b = j;
                j--;
            }
        }
        if (A[i] + B[j] > C)
            j--;
        else
            i++;
    }
    vector<int> ans = {A[a], B[b]};
    return ans;
}
