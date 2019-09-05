int Solution::longestSubsequenceLength(const vector<int> &A)
{

    int sz = int(A.size());
    if (!sz)
        return 0;
    vector<int> dpi(sz, 1);
    vector<int> dpd(sz, 1);
    vector<int> ma(sz, 1);
    for (int i = 1; i < sz; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                dpi[i] = max(dpi[i], dpi[j] + 1);
            }
        }
    }
    for (int i = sz - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (A[j] < A[i])
            {
                dpd[i] = max(dpd[i], dpd[j] + 1);
            }
        }
    }
    transform(dpi.begin(), dpi.end(), dpd.begin(), ma.begin(), plus<int>());
    int ans = *max_element(ma.begin(), ma.end()) - 1;
    return ans;
}
