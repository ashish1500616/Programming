#define ll long long int
int prefix_sum(vector<ll> &psa, int m, ll B)
{
    int n = psa.size();             //6 , m=2 B=10
    for (int i = 0; i < n - m; i++) // 4+2 6
    {
        if ((psa[i + m] - psa[i]) > B)
            return 0;
    }
    return 1;
}
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<ll> psa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        psa[i] = psa[i - 1] + A[i - 1];
    }
    int l = 0;
    int r = A.size();
    int mid = 0;
    int ans = 0;
    while (l <= r)
    {
        mid = (r - l) / 2 + l;
        // cout<< l << " " << r <<" " << mid << " " << "\n";
        if (prefix_sum(psa, mid, B))
        {
            ans = mid;
            l = mid + 1;
            // cout<<ans<<"\n";
        }
        else
            r = mid - 1;
    }
    return ans;
}
