int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int r = -1, s;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        s = 0;
        for (j = 0; j < n; j++)
        {
            int a = (i + j) % n;
            int b = (i + j) % n;
            s += A[a] - B[b];
            if (s < 0)
                break;
        }
        if (j == n)
        {
            r = i;
            break;
        }
    }
    return r;
}