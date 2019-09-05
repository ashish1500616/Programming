int expoMod(int a, int b, int c)
{
    if (b == 0)
        return 1;
    long long ans = expoMod(a, b / 2, c);
    ans %= c;
    ans *= (ans * 1LL);
    ans %= c;
    if (b & 1)
    {
        ans *= (a * 1LL);
        ans %= c;
    }
    return (ans + c) % c;
}
int Solution::Mod(int A, int B, int C)
{
    if (!A)
        return A;
    return expoMod(A, B, C);
}
