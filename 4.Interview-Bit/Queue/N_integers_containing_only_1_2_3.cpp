× vector<int> Solution::solve(int A)
{
    queue<int> q;
    for (int j = 1; j <= 3; j++)
    {
        q.push(j);
    }
    vector<int> ans(A, 0);
    for (int i = 0; i < A; i++)
    {
        ans[i] = q.front();
        q.pop();
        for (int j = 1; j <= 3; j++)
        {
            q.push(ans[i] * 10 + j);
        }
    }
    return ans;
}