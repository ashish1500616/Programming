#define w(n) cout << (#n) << "\tis\t" << n << "\n"
vector<int> Solution::lszero(vector<int> &A)
{
    int n = int(A.size());

    vector<int> ps(n + 1);

    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + A[i];
    }
    map<int, int> mp;
    pair<int, int> in;
    int m_v = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        if (mp.find(ps[i]) == mp.end())
        {
            mp.insert({ps[i], i});
        }
        else
        {
            int dist = i - mp[ps[i]];
            if (dist > m_v)
            {
                m_v = dist;
                in.first = mp[ps[i]];
                in.second = i;
            }
        }
    }
    vector<int> ans(A.begin() + (in.first), A.begin() + (in.second));
    return ans;
}
