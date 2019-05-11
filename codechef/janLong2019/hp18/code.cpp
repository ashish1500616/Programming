#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<float> vf;
typedef vector<ld> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef long long ll;
typedef long double ld;

ll maxi = LLONG_MAX;
ll mini = LLONG_MIN;

#define inf 1e9
#define mod 1000000007


#define vec(x) vector<x>
#define sz(a) int((a).size())
#define p(x, y) pair<x, y>
#define pb push_back
#define mp make_pair
#define vput(a)                                                                                    \
    rep(i, 0, a.z) pls(a[i]);                                                                      \
    nl;
#define vsort(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()


#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define endl '\n'
#define nl cout << '\n';


#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vuni(v) v.erase(unique(all(v)), v.end())
#define X first
#define Y second
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define total(v) accumulate(all(v), ll(0))
#define tr(c)                                                                                      \
    for (auto it : (c))                                                                            \
    {                                                                                              \
        cout << it << " ";                                                                         \
    }
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define eb(a, b) (a).emplace_back(b)

#define bs(v, x) binary_search(all(v), x)
#define parray(a, n)                                                                               \
    rep(i, 0, n) pls(a[i]);                                                                        \
    nl;

#define ppair(x)                                                                                   \
    cout << x.first                                                                                \
         << 'cond line of each testcase contains nn space-separated integers a1,a2,…,an '        \
         << x.second << "\n";


#define w(a) while (a--)
#define wh(a) while (a)
#define rep(i, begin, end)                                                                         \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end));            \
         i += 1 - 2 * ((begin) > (end)))


void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// macro to debug function
#define error(args...)                                                                             \
    {                                                                                              \
        string _s = #args;                                                                         \
        replace(_s.begin(), _s.end(), ',', ' ');                                                   \
        stringstream _ss(_s);                                                                      \
        istream_iterator<string> _it(_ss);                                                         \
        err(_it, args);                                                                            \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << "\n";
    err(++it, args...);
}

#define setpr fixed << setprecision
#define gl(a) getline(cin, a)
#define ppb pop_back
#define pow2(x) ((x) * (x))
#define modnum(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define con continue
#define bk break
#define ret return
#define fl flush
#define pq priority_queue

void printWinner(int win)
{
    if (win)
        put("ALICE\n");
    else
        put("BOB\n");
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast();
    int t;
    get(t);
    w(t)
    {
        int n, a, b, i = 0, count = 0;
        get(n >> a >> b);
        // if (a == b)
        // {
        //     rep(i, 0, n)
        //     {
        //         int h;
        //         get(h);
        //         if (!(h % a))
        //         {
        //             count++;
        //         }
        //     }
        //     if (count & 1)
        //     {
        //         printWinner(0);
        //     }
        //     else
        //     {
        //         printWinner(1);
        //     }
        // }
        // else
        // {
            int l = lcm(a, b);
            int da = 0, db = 0;
            rep(i, 0, n)
            {
                int h;
                get(h);
                if (h % a == 0)
                    da++;
                else if (h % b == 0)
                    db++;
                else if (h % l == 0)
                    count++;
            }
            if (count > 0 && count & 1)
            {
                if (da == db)
                {
                    printWinner(0);
                }
                else if (db > da)
                {
                    printWinner(1);
                }
                else if (da > db)
                {
                    printWinner(0);
                }
            }
            else
            {
                if (da == db)
                {
                    printWinner(1);
                }
                else if (db > da)
                {
                    printWinner(1);
                }
                else if (da > db)
                {
                    printWinner(0);
                }
            }
        // }
    }
return 0;
}
