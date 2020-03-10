#include <bits/stdc++.h>
using namespace std;

long fast_expo(long a, long b)
{
    if (b == 1)
    {
        return a;
    }
    long ans = fast_expo(a, b / 2);
    ans *= ans;
    if (b & 1)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    cout << fast_expo(2, 10);
    return 0;
}