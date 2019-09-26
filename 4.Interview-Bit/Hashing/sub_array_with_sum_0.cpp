int Solution::solve(vector<int> &A)
{
    using ll = long long;
    unordered_set<ll> sa;
    int n = A.size();
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0 || sa.count(sum) != 0)
            return 1;
        sa.insert(sum);
    }
    return 0;
}
