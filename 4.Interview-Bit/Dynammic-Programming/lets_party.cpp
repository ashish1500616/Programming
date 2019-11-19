#define MOD 10003
// recursive Function.
int fibPattern(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    int danceWithoutPairingUp = fibPattern(n - 1);
    int dancePairingUp = (n - 1) * fibPattern(n - 2);
    return (danceWithoutPairingUp + dancePairingUp) % MOD;
}
int Solution::solve(int A)
{
    // bottom Up.
    vector<int> dp(A + 1);
    dp[1] = 1; // 1 Person can dance only in 1 way.
    dp[2] = 2; // 2 person can dance in two ways (A,B) or (A,B);
    for (int i = 2; i <= A; i++)
    {
        dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % MOD;
    }
    return dp[A];
}
