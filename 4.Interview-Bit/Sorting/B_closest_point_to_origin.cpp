#define w(n) cout << (#n) << "\t" << n << "\n"
#define ll long long
vector<vector<int>> Solution::solve(vector<vector<int>> &A, int B)
{
    int n = A.size();
    vector<pair<ll, int>> ip(n);
    for (int i = 0; i < n; i++)
    {
        ip[i].second = i;
        ip[i].first = (1ll * A[i][0] * 1ll * A[i][0]) + (1ll * A[i][1] * 1ll * A[i][1]);
    }
    // sort(ip.begin(),ip.end(),[](pair<ll,int> a, pair<ll,int> b) { return a.first< b.first;});
    sort(ip.begin(), ip.end());
    vector<vector<int>> ans;
    for (int i = 0; i < B; i++)
    {
        ans.push_back(A[ip[i].second]);
    }
    return ans;
}
