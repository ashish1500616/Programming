#define mod 1000003
int fact(int n)
{
    return (n <= 1) ? 1 : (n * fact(n - 1)) % mod;
}

int findSmallerInRight(string str, int l, int h)
{
    int cr = 0;
    for (int i = l + 1; i < h; i++)
    {
        if (str[i] < str[l])
        {
            cr++;
        }
    }
    return cr;
}

int Solution::findRank(string A)
{
    int l = int(A.size());
    int fact_val = fact(l);
    int rank = 1;
    int countRight;
    for (int i = l - 1; i >= 0; i--)
    {
        fact_val = fact(l - i - 1);
        countRight = findSmallerInRight(A, i, l);
        rank += countRight * fact_val;
        rank %= mod;
    }
    return rank;
}