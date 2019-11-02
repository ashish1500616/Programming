#include <bits/stdc++.h>
using namespace std;

int msd(vector<int> &A)
{
    int sum = accumulate(A.begin(), A.end(), 0);
    sum >>= 1;
    sum += 1;
    int n = A.size();
    vector<vector<int>> M(n, vector<int>(sum, 0));
    for (int i = 0; i < n; i++)
    {
        M[i][0] = 1;
    }
    for (int i = 0; i < sum; i++)
    {
        if (A[0] == i)
            M[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < sum; j++)
        {
            if (M[i - 1][j] || (A[i] <= j && M[i - 1][j - A[i]]))
            {
                M[i][j] = 1;
            }
        }
    }
    int checkClosestNumber = sum - 1;
    while (checkClosestNumber >= 0 && M[n - 1][checkClosestNumber] == 0)
    {
        --checkClosestNumber;
    }
    int sub2 = accumulate(A.begin(), A.end(), 0) - checkClosestNumber;
    return abs(sub2 - checkClosestNumber);
}
int main()
{
    vector<int> A = {1, 3, 4, 100};
    int ans = 0;
    ans = msd(A);
    cout << ans << "\n";
    return ans;
}