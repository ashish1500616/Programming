#include <bits/stdc++.h>
using namespace std;

// recursive solution
int minStepRecursive(int n) {
  if (n <= 1)
    return 0;
  else
    return min(1 + minStepRecursive(n - 1),
               min(1 + minStepRecursive(n / 2), 1 + minStepRecursive(n / 3)));
}
int minStepRecursiveTopDown(int n, int *dp) {
  if (n <= 1) {
    return 0;
  }

  if (dp[n] != -1) {
    return dp[n];
  }
  int sub1 = INT_MAX, sub2 = INT_MAX, sub3 = INT_MAX;
  if (n > 1) {
    sub1 = 1 + minStepRecursiveTopDown(n - 1, dp);
  }
  if (!n % 2) {
    sub2 = 1 + minStepRecursiveTopDown(n / 2, dp);
  }
  if (n % 3 == 0) {
    sub3 = 1 + minStepRecursiveTopDown(n / 3, dp);
  }
  return dp[n] = min(sub1, min(sub2, sub3));
}
int dp[20000000];
void minStepBottomUp() {
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= 2 * 10000000; i++) {
    dp[i] = 1 + dp[i - 1];
    if (i % 2 == 0) {
      dp[i] = min(dp[i], 1 + dp[i / 2]);
    }
    if (i % 3 == 0) {
      dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
  }
  return;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast();
  int n;
  cin >> n;
  for (int i = 0; i <= 2 * 10000000; i++) {
    dp[i] = 0;
  }
  minStepBottomUp();
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    int ans = dp[val];
    cout << "Case " << i << ": " << ans << "\n";
  }
}
