vector<int> Solution::solve(vector<int> &A, int B)
{
    queue<int> q;
    vector<int> ans(A);
    int siz = int(A.size());
    for (int i = 0; i < B; i++)
        q.push(ans[i]);
    for (int i = B - 1; i >= 0; i--)
    {
        ans[i] = (q.front());
        q.pop();
    }
    return ans;
}