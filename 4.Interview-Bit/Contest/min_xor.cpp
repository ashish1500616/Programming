int powExpo(int a, int b)
{
    if (b == 0)
        return 1;
    int ans = powExpo(a, b / 2);
    ans *= ans;
    if (b & 1)
        ans *= a;
    return ans;
}

int ver(vector<int> r)
{
    int x = 0;
    for (int i = 0; i < 40; i++)
    {
        if (r[i] == 1)
        {
            x += powExpo(2, i);
        }
    }
    return x;
}
int Solution::solve(int A, int B)
{
    vector<int> hash(40, 0);
    int i = 0;
    int s = 0;
    int x = A;
    while (A)
    {
        if (A & 1)
        {
            hash[i] = 1;
            s++;
        }
        A >>= 1;
        i++;
    }
    if (s == B)
        return x;
    vector<int> r;
    r = hash;
    if (s < B)
    {
        int d = B - s;
        for (i = 0; i < 40; i++)
        {
            if (r[i] == 0 && d)
            {
                r[i] = 1;
                d--;
            }
        }
        return ver(r);
    }
    else
    {
        int d = s - B;
        for (int j = 0; j < 40; j++)
        {
            if (r[j] == 1 && d)
            {
                r[j] = 0;
                d--;
            }
        }
        return ver(r);
    }
}