bool checkDiagonal(vector<vector<int>> &A, int i, int j)
{
    int v = A[i][j];
    while (++i < A.size() && ++j < A[0].size())
    {
        if (A[i][j] != v)
            return false;
    }
    return true;
}
bool isToeplitz(vector<vector<int>> &A)
{
    //Check each row
    for (int i = 0; i < A.size(); i++)
    {
        if (!checkDiagonal(A, i, 0))
        {
            return false;
        }
    }
    //Check each Column
    for (int i = 0; i < A[0].size(); i++)
    {
        if (!checkDiagonal(A, 0, i))
        {
            return false;
        }
    }
    return true;
}
int Solution::solve(vector<vector<int>> &A)
{
    return isToeplitz(A);
}
