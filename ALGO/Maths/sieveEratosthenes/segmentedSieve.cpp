#include <bits/stdc++.h>
using namespace std;

#define max 1000000
#define ll long long

void sieve(ll *p) {
  // memset(p, 1, sizeof(p));
  for (int i = 0; i <= max; i++)
    p[i] = 1;
  for (ll i = 3; i * i <= max; i += 2) {
    if (p[i]) {
      for (ll j = i * i; j <= max; j += 2 * i) {
        p[j] = 0;
      }
    }
  }
}

int main() {
  int tc;
  ll prime[max];
  sieve(prime);
  cin >> tc;
  while (tc--) {
    ll a, b;
    cin >> a >> b;
    bool segment[b - a + 1];
    memset(segment, 1, sizeof(segment));

    for (ll i = 2; i * i <= b; i++) {
      for (ll j = a; j <= b; j++) {
        if (prime[i]) {
          // cout<<"i \t"<<i<<endl;
          if (j == i)
            continue;
          if (j % i == 0)
            segment[j - a] = 0;
        }
      }
    }
    for (ll i = a; i <= b; i++) {
      if (segment[i - a] == 1)
        cout << i << "\n";
    }
    cout << endl;
  }

  return 0;
}

/*

Time Complexity analysis of the code .

DISCUSS ??



*/
