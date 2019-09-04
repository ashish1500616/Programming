#include <bits/stdc++.h>
using namespace std;

int main() {
  // findPrime();
  long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  long n, maxvalue = -1;
  cin >> n;
  while (n--) {
    long m;
    cin >> m;
    long count = 0;
    long product = 1;
    for (long i = 0; i < 15; i++) {
      product *= primes[i];
      if (product <= m)
        count++;
    }
    cout << count << endl;
  }

  return 0;
}
