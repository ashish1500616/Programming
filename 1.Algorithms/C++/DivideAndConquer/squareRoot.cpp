#include <bits/stdc++.h>
using namespace std;
float squareRoot(int n, int p)
{
  int s = 0, e = n, mid;
  float ans = 0;
  while (s <= e)
  {
    mid = (s + e) / 2;
    int square = mid * mid;
    if (square == n)
    {
      ans = mid;
      break;
    }
    if (square < n)
    {
      s = mid + 1;
      ans = mid;
    }
    else
    {
      e = mid - 1;
    }
  }

  float inc = 0.1;
  while (p--)
  {
    while (ans * ans <= n)
    {
      ans += inc;
    }
    ans -= inc;
    inc = inc / 10;
  }
  return ans;
}
int main()
{
  int val;
  cin >> val;
  cout << squareRoot(val, 3) << endl;
  return 0;
}

// Time COmplexity = O(logn + 9K) =O(logn)
// INPUT =10
// OUTPUT=3.162
