#define ll long long
#define mod 1000000007
void prefixSum(int n, vector<int> &ps, vector<int> A)
{
    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + A[i];
    }
}
int Solution::getSum(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F)
{
    sort(D.begin(), D.end());
    sort(F.begin(), F.end());
    vector<int> psA(A + 1);
    vector<int> psC(C + 1);
    prefixSum(A + 1, psA, D);
    prefixSum(C + 1, psC, F);
    ll sum = 0;
    for (int i = 0; i < B; i++)
    {
        ll countA = (upper_bound(D.begin(), D.end(), E[i]) - D.begin());
        ll countC = (upper_bound(F.begin(), F.end(), E[i]) - F.begin());
        sum += ((1LL * (E[i] * countA + psA[countA])) * (E[i] * countC + psC[countC]));
        sum %= mod;
    }
    return sum;
}
