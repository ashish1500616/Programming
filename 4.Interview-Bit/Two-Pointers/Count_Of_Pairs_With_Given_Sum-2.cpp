int Solution::solve(vector<int> &A, int B)
{
    int i = 0, j = A.size() - 1;
    long long ans = 0;
    while (i < j)
    {
        if (A[i] + A[j] > B)
            j--;
        else if (A[i] + A[j] < B)
            i++;
        else
        {
            int x = A[i], cnt1 = 0;
            while (A[i] == x && i < A.size())
            {
                i++, cnt1++;
            }
            int y = A[j], cnt2 = 0;
            while (A[j] == y && j >= 0)
            {
                j--, cnt2++;
            }
            if (x == y)
            {
                ans += ((cnt1)*1LL * (cnt1 - 1) / 2);
            }
            else
                ans += cnt1 * 1LL * cnt2;

        }
        ans %= 1000000007;
    }
    return ans;
}
