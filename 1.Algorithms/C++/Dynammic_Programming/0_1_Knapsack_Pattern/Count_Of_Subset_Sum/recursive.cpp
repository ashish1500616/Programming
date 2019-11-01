#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(vector<int> &A, int in, int s)
{
    if (s == 0)
    {
        return 1;
    }
    if (in >= A.size())
    {
        return 0;
    }
    int left = 0;
    if (A[in] <= s)
    {
        left = countSubsetSum(A, in + 1, s - A[in]);
    }
    int right = countSubsetSum(A, in + 1, s);
    return left + right;
}
int main()
{
    vector<int> v = {1, 10, 2, 8, 15, 4};
    int ans = countSubsetSum(v, 0, 12);
    cout << ans << "\n";
    return ans;
}