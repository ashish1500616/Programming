int Solution::search(const vector<int> &A, int B)
{
    int l = 0;
    int h = A.size();
    while (l < h)
    {
        int mid = l + ((h - l) >> 1);
        if (A[mid] == B)
        {
            return mid;
        }
        if (A[l] < A[mid])
        {
            if (B >= A[l] && B <= A[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (B >= A[mid] && B <= A[h])
            {
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
    }
    return (A[l] == B) ? l : -1;
}