int Solution::majorityElement(const vector<int> &A)
{
    int ind = 0, c = 1;
    int size = int(A.size());
    for (int i = 1; i < size; i++)
    {
        if (A[ind] == A[i])
            c++;
        else
            c--;
        if (c == 0)
        {
            c = 1;
            ind = i;
        }
    }
    int mv = A[ind];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == mv)
        {
            count++;
        }
        if (count > floor(size / 2))
            break;
    }
    return mv;
}
