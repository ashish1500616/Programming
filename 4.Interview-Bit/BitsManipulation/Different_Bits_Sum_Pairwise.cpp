using ll = long long;
#define mod 1000000007
#define w(n) cout << #n << "\tis\t" << n << "\n"
int Solution::cntBits(vector<int> &A)
{
    ll sum = 0;
    int n = A.size();
    for (int i = 0; i < 32; i++)
    {
        // count number of elements with i'th bit set
        int count = 0;
        for (int j = 0; j < n; j++)
            if ((A[j] & (1 << i)))
                count++;

        // Add "count * (n - count) * 2" to the answer
        sum += (count * 1ll * (n - count) * 2);
        sum %= mod;
    }

    // return ans;
    return sum;
}
