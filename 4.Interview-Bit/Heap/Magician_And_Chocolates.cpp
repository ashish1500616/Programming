#define mod 1000000007
int Solution::nchoc(int A, vector<int> &B)
{
    priority_queue<int> q(B.begin(), B.end());
    int i = 0;
    long long sum = 0;
    while (i < A)
    {
        long long top = q.top();
        q.pop();
        sum += top * 1ll;
        sum %= mod;
        q.push(floor(top / 2));
        ++i;
    }
    return sum;
}
