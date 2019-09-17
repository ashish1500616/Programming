string Solution::solve(string A)
{
    queue<char> q;
    vector<int> h(27, 0);
    string ans = "";
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        int in = (int(A[i]) - 97);
        q.push(A[i]);
        h[in] += 1;
        while (!q.empty() && h[(int(q.front()) - 97)] != 1)
            q.pop();
        if (!q.empty())
            ans += q.front();
        else
            ans += "#";
    }
    return ans;
}