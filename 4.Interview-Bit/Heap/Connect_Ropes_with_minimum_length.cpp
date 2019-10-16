int Solution::solve(vector<int> &A)
{
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    int ans = 0;
    while (pq.size() != 1)
    {
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();
        int sum = top1 + top2;
        ans += sum;
        pq.push(sum);
    }
    return ans;
}
