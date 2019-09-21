int Solution::singleNumber(const vector<int> &A)
{
    int ans = 0;
    vector<int> bits(32, 0);
    for (auto X : A)
    {
        int n = X;
        int i = 0;
        while (n)
        {
            bits[i++] += (n & 1);
            n = n >> 1;
        }
    }
    int p = 1;
    for (auto &X : bits)
    {
        X %= 3;
        ans += (X * p);
        p = p << 1;
    }
    return ans;
}
