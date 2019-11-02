#include <bits/stdc++.h>
using namespace std;

int msd(vector<int> &A, int index, int ss1, int ss2)
{
    if (index == A.size())
    {
        return abs(ss1 - ss2);
    }
    int ssv1 = msd(A, index + 1, ss1 + A[index], ss2);
    int ssv2 = msd(A, index + 1, ss1, ss2 + A[index]);
    return min(ssv1, ssv2);
}

int main()
{
    vector<int> A = {1, 3, 4, 100};
    int ans = 0;
    ans = msd(A, 0, 0, 0);
    cout << ans << "\n";
    return ans;
}