int Solution::divide(int A, int B)
{
    using ll = long long;
    int sign = ((A < 0 && B < 0) || (A > 0 && B > 0)) ? 1 : -1;

    if (A == INT_MIN && B == -1)
        return INT_MAX;
    else if (A == INT_MIN && B == 1)
        return -1 * INT_MIN;
    else if (A == INT_MAX && B == -1)
        return -1 * INT_MIN;
    else if (A == INT_MAX && B == 1)
        return INT_MAX;

    ll tA = abs(1LL * A);
    ll tB = abs(1LL * B);

    int q = 0;
    while (tA >= tB)
    {
        tA -= tB;
        q++;
    }

    return sign * q;
}
