int Solution::maxProduct(const vector<int> &A)
{
    int sz = A.size();
    int p_max = A[0];
    int p_min = A[0];
    int c_max;
    int c_min;
    int ans = A[0];
    for (int i = 1; i < sz; i++)
    {
        c_max = max(p_max * A[i], max((A[i] * p_min), A[i]));
        c_min = min(p_max * A[i], min((A[i] * p_min), A[i]));
        ans = max(ans, c_max);
        p_max = c_max;
        p_min = c_min;
    }
    return ans;
}
