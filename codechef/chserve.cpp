#include <bits/stdc++.h>
using namespace std;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
// macro to debug function
#define error(args...)                                                         \
  {                                                                            \
    string _s = #args;                                                         \
    replace(_s.begin(), _s.end(), ',', ' ');                                   \
    stringstream _ss(_s);                                                      \
    istream_iterator<string> _it(_ss);                                         \
    err(_it, args);                                                            \
  }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>

void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}

void PassFunction(string ck, int p2, int who, int k) {
  if (who == 1) {
    swap(ck[0], ck[1]);
  }
  if (p2 % k == 0) {
    cout << ck[((p2 / k) % 2)];
  } else {
    int findOut = (p2 / k) % 2;
    if (findOut) {
      cout << ck[0];
    } else {
      cout << ck[1];
    }
  }
}

int main() {
  // your code goes here
  int t;
  while (t--) {
    int p1, p2, k;
    string cheforcook = {"chef", "cook"};
    cin >> p1 >> p2 >> k;
    if (p1 % k == 0) {
      int whoIsServer = (p1 / k) % 2;
      error(whoIsServer);
      PassFunction(cheforcook, p2, whoIsServer, k);
    } else {
      int divid = p1 / k;
      int ndk = divid * k;
      int servedTimesOutOfK = p1 - ndk;
      int temp = k;
      temp -= servedTimesOutOfK;
      p2 -= temp;
      int whoIsServer = ndk % 2;
      error(whoIsServer);
      PassFunction(cheforcook, p2, whoIsServer, k);
    }
  }
  return 0;
}
