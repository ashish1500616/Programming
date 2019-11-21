
// Unsorted Read Only Array Find the Kth Minimum.
bool helper(const vector<int> &A, int v, int B)
{
    int cnt = 0;
    for (auto x : A)
    {
        if (x <= v)
        {
            cnt++;
        }
    }
    if (cnt >= B)
    {
        return 1;
    }
    return 0;
}
int Solution::kthsmallest(const vector<int> &A, int B)
{
    int mine = *min_element(A.begin(), A.end());
    int maxe = *max_element(A.begin(), A.end());
    int l = mine - 1;
    int h = maxe;
    while (h - l > 1)
    {
        int mid = l + ((h - l) >> 1);
        if (helper(A, mid, B) == 1)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    return h;
}