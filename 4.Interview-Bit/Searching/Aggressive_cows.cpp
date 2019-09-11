int check_if_possible_to_arrange_cow_x_dist(vector<int> &A, int c, int x)
{
    int n = int(A.size());
    int n_cow = 1, pos = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] - pos >= x)
        {
            n_cow++;
            if (n_cow == c)
                return 1;
            pos = A[i];
        }
    }
    return 0;
}
int Solution::solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int l = 1; // Minimum Distance between two Stalls.
    int h = A[n - 1] - A[0]; // Maximum Distance Between Two Stalls.
    int m_i = 0;
    while (l <= h)
    {
        int mid = (h + l) / 2;
        if (check_if_possible_to_arrange_cow_x_dist(A, B, mid) == 1)
        {
            m_i = max(m_i, mid);
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return m_i;
}