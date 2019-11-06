int depth(int &count, int i, int n, int B)
{
    if (i >= n)
    {
        return -1;
    }
    int l = depth(count, 2 * i + 1, n, B);
    int r = depth(count, 2 * i + 2, n, B);
    int c_d = 1 + max(l, r);
    if (c_d == B)
    {
        count += 1;
    }
    return c_d;
}
vector<int> Solution::solve(int A, int B)
{
    vector<int> ans = {0, 0};
    int count = 0;
    depth(count, 0, A, B);
    double l = log2(A);
    if (B < int(l))
    {
        ans[0] = 1 << B;
    }
    else if (B == int(l))
    {
        ans[0] = A - ((1 << (int(B))) - 1);
    }
    ans[1] = count;
    return ans;
}