#define pii pair<int, int>
#define ll long long int
#define MOD 1000000007
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    // we will keep two queues,
    priority_queue<pii> max_queue;
    priority_queue<pii, vector<pii>, greater<pii>> min_queue;
    ll r = 0;
    for (int i = 0; i < B; i++)
    {
        max_queue.push({A[i], i});
        min_queue.push({A[i], i});
    }
    r += 1LL * max_queue.top().first;
    r %= MOD;
    r += 1LL * min_queue.top().first;
    r %= MOD;
    for (int i = B; i < n; i++)
    {
        while (max_queue.top().second <= i - B)
            max_queue.pop();
        while (min_queue.top().second <= i - B)
            min_queue.pop();
        max_queue.push({A[i], i});
        min_queue.push({A[i], i});
        r += 1LL * max_queue.top().first;
        r %= MOD;
        r += 1LL * min_queue.top().first;
        r %= MOD;
    }
    r = (r + MOD) % MOD;
    return r;
}
