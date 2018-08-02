#include <bits/stdc++.h>
using namespace std;

#define max 1000000
void prime(int *p) {

  p[0] = 0;
  p[1] = 0;

  // Insted we can alse use memset to set all the bytes to 1 initially.

  for (int i = 2; i <= max; i++) {
    p[i] = 1;
  }

  for (int i = 2; i <= max; i++) {
    if (p[i]) {
      for (int j = i * 2; j <= max; j += i) {
        p[j] = 0;
      }
    }
  }
}

int main() {
  int arr[max];

  prime(arr);

  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    if (arr[i]) {
      cout << i << "\n";
    }
  }
}

/*

Time Complexity analysis of the code .

DISCUSS ??



*/
