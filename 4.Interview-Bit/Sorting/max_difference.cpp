#define ll long long int
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    ll x = 0, y = 0, s = 0;
    sort(A.begin(), A.end());
    s = accumulate(A.begin(), A.end(), 0);
    for (int i = 0; i < B; i++)
        x += A[i];
    for (int i = n - 1; i >= n - B; i--)
        y += A[i];
    return max(abs(2L * x - s), abs(2L * y - s));
}
