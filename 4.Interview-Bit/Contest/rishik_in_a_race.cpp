int Solution::solve(int A, vector<int> &B)
{
    for (auto x : B)
    {
        if (A - 1 == x)
        {
            A = x;
        }
        else if (A == x)
        {
            A++;
        }
    }
    return A;
}
