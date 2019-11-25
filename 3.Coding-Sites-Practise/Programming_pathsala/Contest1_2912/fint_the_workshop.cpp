#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nb, ns;
    cin >> nb >> ns;
    vector<ll> a;
    for (int i = 0; i < nb; i++)
    {
        ll h;
        cin >> h;
        a.push_back(h);
    }
    vector<ll> ps(nb, 0);
    ps[0] = a[0];
    for (int i = 1; i < nb; i++)
    {
        ps[i] = a[i] + ps[i - 1];
    }
    while (ns--)
    {
        ll r;
        cin >> r;
        ll l = -1;
        ll h = nb;
        while (h - l > 1)
        {
            ll m = (l + h) / 2;
            if (r <= ps[m])
            {
                h = m;
            }
            else
            {
                l = m;
            }
        }
        // cout<<ps[l]<<"\n";
        cout << h + 1 << " " << ((l == -1) ? r : r - ps[l]) << "\n";
    }
    return 0;
}