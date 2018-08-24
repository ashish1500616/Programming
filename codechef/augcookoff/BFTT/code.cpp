#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ans = 0;
    for (long long i = n + 1;; i++) {
      int count = 0;
      long long temp = i;
      while (temp) {
        if (temp % 10 == 3) {
          count++;
        }
        if (count == 3) {
          ans = 1;
          cout << i << endl;
          break;
        }
        temp = temp / 10;
      }
      if (ans)
        break;
    }
  }
  return 0;
}
