int Solution::solve(int A)
{
    int c = 0;
    for (int i = 1; (A - i) >= i; i++)
    {
        if ((A - i) % i == 0)
            ++c;
    }
    return c;
}