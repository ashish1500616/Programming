int SumRange(vector<int> &A, int x, int y)
{
    int s = 0;
    for (int i = x; i <= y; i++)
    {
        s += A[i];
    }
    return s;
}
vector<int> Solution::solve(vector<int> &A, vector<vector<int>> &B)
{
    vector<int> ans;

    for (auto x : B)
    {
        if (x[0] == 1)
            A.push_back(x[1]);
        else if (x[0] == 2)
            A[x[1] - 1] = x[2];
        else if (x[0] == 3)
            A.erase(A.begin() + (x[1] - 1));
        else if (x[0] == 4)
            ans.push_back(SumRange(A, x[1] - 1, x[2] - 1));
    }
    return ans;
}
