int Solution::solve(vector<int> &A)
{
    int maxx = 0, mask = 0;
    set<int> s;
    int n = int(A.size());
    for (int i = 31; i >= 0; i--)
    {
        mask = mask | (1 << i);
        for (int i = 0; i < n; i++)
        {
            s.insert(A[i] & mask);
        }
        int newMax = maxx | (1 << i);
        for (auto prefix : s)
        {
            if (s.count(newMax ^ prefix))
            {
                maxx = newMax;
                break;
            }
        }
        s.clear();
    }
    return maxx;
}
