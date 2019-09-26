#define mod 1000000007
#define ll long long
#define w(n) cout << (#n) << "   is   " << n << "\n";
ll exp(int a, int b)
{
    if (b == 0)
        return 1;
    a %= mod;
    ll ans = exp(a, b / 2);
    ans *= ans;
    if (b & 1)
        ans *= a * 1ll;
    ans %= mod;
    return ans;
}
// int exp(ll a, ll b){
//     ll r = 1;
//     a%=mod;
//     while(b){
//         if(b&1)
//             r=(a*r)%mod;
//         a=(a*a)%mod;
//         b=b>>1;
//     }
//     return r;
// }
int Solution::solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = int(A.size());
    ll sumL = 0, sumF = 0, i = 0;
    int ans = 0;
    for (auto x : A)
    {
        sumF += (x * 1LL * exp(2, n - i - 1));
        sumL += (x * 1LL * exp(2, i));
        i++;
    }
    // cout<<sumF << " "<<sumL<<endl;
    // w(sumF);
    // w(sumL);
    ans = (sumL - sumF) % mod;
    return ans;
}
