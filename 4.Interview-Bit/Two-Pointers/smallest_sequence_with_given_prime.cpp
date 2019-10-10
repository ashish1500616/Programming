int min3(int x, int y, int z)
{
    return min(x, min(y, z));
}
vector<int> Solution::solve(int A, int B, int C, int D)
{
    vector<int> r;
    vector<int> p(3);
    p[0] = A;
    p[1] = B;
    p[2] = C;
    sort(p.begin(), p.end());
    int j = 0;
    A = p[0];
    B = p[1];
    C = p[2];
    int a, b, c;
    a = b = c = 0;
    for (int i = 0; i < D; i++)
    {
        if (A <= B && A <= C)
        {
            if (i > 0 && r[i - 1] == A)
            {
                i--;
                A = r[a++] * p[0];
                continue;
            }
            r.push_back(A);
            A = r[a++] * p[0];
        }
        else if (B <= C && B <= A)
        {
            if (i > 0 && r[i - 1] == B)
            {
                i--;
                B = r[b++] * p[1];
                continue;
            }
            r.push_back(B);
            B = r[b++] * p[1];
        }
        else
        {
            if (i > 0 && r[i - 1] == C)
            {
                i--;
                C = r[c++] * p[2];
                continue;
            }
            r.push_back(C);
            C = r[c++] * p[2];
        }
    }
    // r
    return r;
}
