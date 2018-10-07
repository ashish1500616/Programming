#include <bits/stdc++.h>
using namespace std;

#define ll long

vector<vector<ll>> M(1700, vector<ll>(3, 0));

void findP() {
  ll bound[6];
  bound[0] = 0, bound[1] = 1, bound[2] = 2, bound[3] = 9, bound[4] = 10,
  bound[5] = 25;
  ll keyv = 1;
  while (bound[5] <= 1700) {
    for (int i = bound[0]; i <= bound[1]; i++) {
      M[i][0] = keyv;
    }
    for (int i = bound[2]; i <= bound[3]; i++) {
      M[i][1] = keyv;
    }
    for (int i = bound[4]; i <= bound[5]; i++) {
      M[i][2] = keyv;
    }
    for (int i = 0; i < 6; i++)
      bound[i] += 26;
    keyv *= 2;
  }
}

int main() {
  findP();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n -= 1;
    cout << M[n][0] << " " << M[n][1] << " " << M[n][2] << endl;
  }
  return 0;
}
