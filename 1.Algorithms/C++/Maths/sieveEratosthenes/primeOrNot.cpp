// Check If a number is prime or not.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  bool state = true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      state = false;
      break;
    }
  }
  (state) ? cout << "YES\n" : cout << "NO\n";

  return 0;
}
