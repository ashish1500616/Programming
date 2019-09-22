#define ll long long
int Solution::solve(int A)
{
    int countr = 0;
    for (ll i = 1; i <= A; i *= 10)
    {
        ll divider = i * 10;
        countr += (A / divider) * i + min(max(A % divider - i + 1, 0LL), i);
    }
    return countr;
}