#define m 1000000007
#define ll long long int
int Solution::solve(vector<int> &A, int B)
{
    vector<ll> kbuc(B, 0);

    // Count Remainders when dividing each number
    for (auto x : A)
    {
        ++kbuc[(x % B)];
    }
    // Handling the case of when Array Element Is Completely Divisible by K
    ll ans = 0;
    ans = ((kbuc[0] * (kbuc[0] - 1LL)) / 2LL);
    ans %= m;
    for (int i = 1; i <= int(B / 2); i++)
    {
        if ((!(B & 1)) && i == B - i)
        {
            ans += ((kbuc[i] * (kbuc[i] - 1)) / 2);
            ans %= m;
            continue;
        }
        ans += (kbuc[i] * kbuc[B - i]);
        ans %= m;
    }
    return ans;
}
