#define pii pair<int, int>
int Solution::solve(vector<int> &A, vector<int> &B)
{
    vector<pii> hm;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        hm.push_back({B[i], A[i]});
    }
    sort(hm.rbegin(), hm.rend());
    int mx = *max_element(A.begin(), A.end());
    vector<int> s(mx + 1, 0);
    for (auto x : hm)
    {
        // cout<<x.first<<" "<<x.second<<"\n";
        if (s[x.second] == 0)
        {
            s[x.second] = x.first;
        }
        else
        {
            int in = x.second;
            while (in >= 0 && s[in] != 0)
            {
                --in;
            }
            if (in > 0 && s[in] == 0)
                s[in] = x.first;
        }
    }
    return accumulate(s.begin(), s.end(), 0);
}