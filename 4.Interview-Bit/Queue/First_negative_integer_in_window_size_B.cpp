#define pii pair<int, int>
vector<int> Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    priority_queue<pii, vector<pii>, greater<pii>> min_queue;
    vector<int> ans;
    for (int i = 0; i < B; i++)
    {
        if (A[i] < 0)
            min_queue.push({i, A[i]});
    }
    if (!min_queue.empty())
        ans.push_back(min_queue.top().second);
    else
        ans.push_back(0);
    for (int i = B; i < n; i++)
    {
        if (A[i] < 0)
            min_queue.push({i, A[i]});
        while (!min_queue.empty() && min_queue.top().first <= i - B)
            min_queue.pop();
        if (!min_queue.empty())
            ans.push_back(min_queue.top().second);
        else
            ans.push_back(0);
    }
    return ans;
}