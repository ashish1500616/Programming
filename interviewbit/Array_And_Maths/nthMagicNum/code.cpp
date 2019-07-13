#include<bits/stdc++.h>
using namespace std;

int solve(int A)
{
    int b[64];
    memset(b, 0, sizeof b);
    int j = 0;
    while (A > 0)
    {
        b[j] = A & 1;
        j++;
        A = A >> 1;
    }
    int ans = 0;
    int mb = 1;
    for (int i = 0; i<j; i++)
    {
        mb = mb * 5;
        ans += b[i] * mb;
        // cout<<i<<endl;
        // cout<<b[i];
    }
    return ans;
}

int main()
{
    int v=3;
    cout<<solve(v)<<endl;
    return 0;
}