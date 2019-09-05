int Solution::solve(vector<int> &A)
{

    // XOR APPROACH O(n)

    // int ans=A[0];
    // for(int i=1;i<A.size();i++)
    // {
    //     ans=ans ^ A[i];
    // }
    // return ans;

    // Binary Search O(log N)

    int sz = A.size();
    int l = 0;
    int h = sz;
    while (l < h)
    {
        int m = int((l + h) / 2);
        if (m & 1)
        {
            if (A[m] == A[m - 1])
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        else
        {
            if (A[m] == A[m + 1])
            {
                l = m + 2;
            }
            else
            {
                h = m;
            }
        }
    }
    return A[l];
}
Single Element in a Sorted Array