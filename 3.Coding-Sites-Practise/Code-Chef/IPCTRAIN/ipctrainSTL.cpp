// 3
// 2 3
// 1 2 300
// 2 2 100
// 2 3
// 1 1 100
// 2 2 300
// 2 3
// 3 2 150
// 1 1 200

#include <bits/stdc++.h>
#define ll long long int
#define tr(c)           \
    for (auto it : (c)) \
    {                   \
        ppair(it)       \
    }
#define ppair(x)          \
    cout                  \
        << x.first << " " \
        << x.second << "\n";
using namespace std;

int main()
{
    int op;
    cin >> op;
    while (op--)
    {
        ll n_t, n_d;
        cin >> n_t >> n_d;
        priority_queue<pair<int, int>> hp;
        vector<vector<pair<int, int>>> h(n_d+1, vector<pair<int, int> >());
        for (int i = 0; i < n_t; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            h[a].push_back(make_pair(c, b));
        }
        int ds = 1;
        while (ds <= n_d)
        {
            if (int(h[ds].size()) > 0)
            {
                for (int it = 0; it < h[ds].size(); it++)
                {
                    hp.push(h[ds][it]);
                }
            }
            if(hp.size()>0)
            {
                pair<int, int> val = hp.top();
                hp.pop();
                val.second = val.second - 1;
                if (val.second > 0)
                {
                    hp.push(val);
                }
            }
                
            ds += 1;
        }
        ll sum = 0;
        while(!hp.empty())
        {
            pair<int,int> data=hp.top();
            sum+=data.first*1L*data.second*1L;
            hp.pop();
        }
        cout << sum << endl;
    }
}