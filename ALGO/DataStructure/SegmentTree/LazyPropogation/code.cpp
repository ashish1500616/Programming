#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
#define mod 1000000007
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

#define vec(x) vector<x>
#define sz(a) int((a).size())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define F(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define vput(a)             \
  rep(i, 0, a.z) pls(a[i]); \
  nl;
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define vuni(v) v.erase(unique(all(v)), v.end())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define total(v) accumulate(all(v), ll(0))
#define tr(c)          \
  for (auto it : (c))  \
  {                    \
    cout << it << " "; \
  }
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define eb(a, b) (a).emplace_back(b)

#define bs(v, x) binary_search(all(v), x)
#define parray(a, n)      \
  rep(i, 0, n) pls(a[i]); \
  nl;
#define ppair(x)                                                                         \
  cout                                                                                   \
      << x.first                                                                         \
      << 'cond line of each testcase contains nn space-separated integers a1,a2,…,an ' \
      << x.second << "\n";
#define vp(x, y) vector<pair<x, y>>
#define p(x, y) pair<x, y>
#define endl '\n'
#define nl cout << '\n';
#define w(a) while (a--)
#define wh(a) while (a)

ll maxi = LLONG_MAX;
ll mini = LLONG_MIN;

void fast()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
// macro to debug function
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
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

#define con continue
#define bk break
#define ret return
#define fl flush
#define setpr fixed << setprecision
#define gl(a) getline(cin, a)
#define ppb pop_back
#define pow2(x) ((x) * (x))
#define modnum(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pq priority_queue
#define fl flush

// Lazy Propogation . Maximum Sum,Range-Update
// TC -O(logn)

void build(ll *tree, ll *arr, ll node, ll start, ll end)
{
  if (start > end)
  {
    return;
  }
  if (start == end)
  {
    tree[node] = arr[start];
    return;
  }
  ll mid = (start + end) >> 1;
  build(tree, arr, 2 * node, start, mid);
  build(tree, arr, node * 2 + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(ll *tree, ll *lazy, ll node, ll start, ll end, ll l, ll r, ll val)
{
  if (lazy[node] != 0)
  {
    tree[node] +=(end-start+1)*lazy[node];
    if (start != end)
    {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || r < start || l > end)
    return;
  if (start >= l && end <= r)
  {
    tree[node] +=(end - start + 1)* val;
    if (start != end)
    {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  ll mid = (start + end) >> 1;
  update(tree, lazy, node * 2, start, mid, l, r, val);
  update(tree, lazy, 2 * node + 1, mid + 1, end, l, r, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll *tree, ll *lazy, ll node, ll start, ll end, ll l, ll r)
{
  if (start > end || r < start || l > end)
  {
    return 0;
  }
  if (lazy[node] != 0)
  {
    tree[node] +=(end-start+1)*lazy[node];
    if (start != end)
    {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }

  if (start >= l && end <= r)
  {
    return tree[node];
  }
  ll mid = (start + end) >> 1;
  ll q1 = query(tree, lazy, 2 * node, start, mid, l, r);
  ll q2 = query(tree, lazy, 2 * node + 1, mid + 1, end, l, r);
  ll val = q1 + q2;
  return val;
}

int main()
{
  ll arr[10001];
  ll tree[40001];
  ll lazy[40001];
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast();
  ll t;
  get(t);
  w(t)
  {
    ll n;
    get(n);
    rep(i, 0, n)
    {
      get(arr[i]);
    }
    ll nq;
    get(nq);
    build(tree, arr, 1, 0, n - 1);
    w(nq)
    {

      ll x, y, op;
      get(op);
      if (op == 1)
      {
        get(x >> y);
        ll val = query(tree, lazy, 1, 0, n - 1, x - 1, y - 1);
        pln(val);
      }
      else if (op == 2)
      {
        ll sr, er, v;
        get(sr >> er >> v);
        // rep(i, 0, 20)
        //     pls(tree[i]);
        // nl;
        update(tree, lazy, 1, 0, n - 1, sr - 1, er - 1, v);
        // rep(i, 0, 20)
        //     pls(tree[i]);
        // nl;
      }
    }
  }
  return 0;
}
