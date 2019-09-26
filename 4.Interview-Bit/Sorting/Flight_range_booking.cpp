vector<int> Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> ans(A, 0);
    for (int i = 0; i < B.size(); i++)
    {
        ans[B[i][0] - 1] += B[i][2];
        if (B[i][1] != A)
            ans[B[i][1]] -= B[i][2];
    }
    for (int i = 1; i < A; i++)
    {
        ans[i] += ans[i - 1];
    }
    return ans;
}
