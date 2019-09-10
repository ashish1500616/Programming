tion to return no of elements less than n int no_of_elem(vector<vector<int>> & A, int n, int r)
{
    int tn = 0;
    for (int i = 0; i < r; i++)
    {
        tn += (upper_bound(A[i].begin(), A[i].end(), n) - A[i].begin());
    }
    return tn;
}
int Solution::findMedian(vector<vector<int>> &A)
{
    int r = A.size();
    int c = A[0].size();
    int l = INT_MAX;
    int h = INT_MIN;
    int n = r * c + 1;

    for (int i = 0; i < r; i++)
    {
        l = (l > A[i].front()) ? A[i].front() : l;
        h = (A[i].back() > h) ? A[i].back() : h;
    }

    int req_n = n / 2;
    while (l < h)
    {
        int mid = (h - l) / 2 + l;
        int now = no_of_elem(A, mid, r);
        if (now < req_n)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
}