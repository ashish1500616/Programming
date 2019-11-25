#include <bits/stdc++.h>
using namespace std;
#define ll long int

void permute(vector<ll> &p, string &s, int i)
{
    if (i == s.size())
    {
        p.push_back(stol(s));
    }
    for (int j = i; j < s.size(); j++)
    {
        swap(s[j], s[i]);
        permute(p, s, i + 1);
        swap(s[j], s[i]);
    }
    return;
}
int main()
{
    ll n;
    cin >> n;
    ll t = n;
    int c = 0, c5 = 0, c9 = 0, c0 = 0;
    while (n > 0)
    {
        int d = n % 10;
        if (d == 5)
        {
            ++c5;
        }
        else if (d == 9)
        {
            c9++;
        }
        else
        {
            c0++;
        }
        c++;
        n = n / 10;
    }
    // Case : When number of 5 == No of 9.
    if (c9 == c5 and c0 == 0)
    {
        cout << t;
        return 0;
    }
    string dom = "";
    string first = "";
    string last = "";
    if (c & 1)
    {
        first += '5';
        last += '9';
    }
    for (int i = 0; i < c / 2; i++)
    {
        first += '5';
        last += '9';
    }
    dom = (first + last);
    vector<ll> perm;
    permute(perm, ans, 0);
    sort(perm.begin(), perm.end());
    cout << *upper_bound(perm.begin(), perm.end(), t);
    return 0;
}