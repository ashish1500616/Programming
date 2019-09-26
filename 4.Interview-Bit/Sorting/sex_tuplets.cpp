#define ll long long
#define w(n) cout << (#n) << "   is   " << n << "\n";
int Solution::solve(vector<int> &A)
{
    ll mod = 1000000007;
    int n = A.size();
    vector<int> RHS;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != 0)
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    RHS.emplace_back(A[i] * (1LL * A[j] + A[k]));
                }
            }
    }
    ll count = 0;
    sort(RHS.begin(), RHS.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ll x = ((1LL * A[i] * A[j] + A[k]));
                count += (upper_bound(RHS.begin(), RHS.end(), x) - lower_bound(RHS.begin(), RHS.end(), x));
                count %= mod;
            }
        }
    }
    return count;
}
//
