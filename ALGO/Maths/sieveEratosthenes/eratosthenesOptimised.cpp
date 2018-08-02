#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define ll long long

void sieveOptim(int *p) {
  for (ll x = 3; x <= MAX; x++) {
    p[x] = 1;
  }
  for (ll i = 3; i * i <= MAX; i += 2) {
    if (p[i] == 1) {
      for (ll j = i * i; j <= MAX; j += 2 * i) {
        p[j] = 0;
      }
    }
  }
}

int main() {
  int arr[MAX];
  // memset(arr, 1, sizeof(arr)*tMAX);
  sieveOptim(arr);
  ll n;
  cin >> n;

  cout << "2\n";

  for (ll i = 3; i < n; i += 2) {
    if (arr[i])
      cout << i << endl;
  }
  return 0;
}
