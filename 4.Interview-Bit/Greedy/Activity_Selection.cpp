#define pii pair<int, int>
int Solution::solve(vector<int> &A, vector<int> &B)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        pq.push({B[i], A[i]});
    }
    pii c = pq.top();
    pq.pop();
    int count = 1;
    while (!pq.empty())
    {
        pii tp = pq.top();
        pq.pop();
        if (c.first <= tp.second)
        {
            ++count;
            c = tp;
        }
    }
    return count;
}
