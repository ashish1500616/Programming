#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> num)
{
    int n = num.size();
    int sum = accumulate(num.begin(), num.end(), 0);
    cout << sum << " ";
    if (sum & 1)
    {
        cout << "Given Array Cant be partitioned\n";
        return false;
    }
    int half_sz = int(sum / 2);
    vector<vector<bool>> dp(n, vector<bool>((half_sz + 1), false));

    // Since Sum =0  Can be formed by empty set.
    for (int r = 0; r < n; r++)
    {
        dp[r][0] = true;
    }
    for (int s = 1; s <= (half_sz); s++)
    {
        // Subset of Sum S containing only one element can be be made only if there is an element present equals to the value of S .
        // Important Sanity Check.
        if (num[0] == s)
        {
            dp[0][s] = true;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= half_sz; s++)
        {
            // True if either Sum can formed (excluding that number) or [(including if the value is less than or equals to S) and
            //(a subset can be formed by subtracting the value of the current element from the current sum) )
            if (dp[i - 1][s] || (s >= num[i] && dp[i - 1][s - num[i]]))
            {
                dp[i][s] = true;
            }
        }
    }
    cout << " Given Array Can Be Equally Partitioned " << dp[n - 1][half_sz] << "\n";

    for (auto x : dp)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}
int main()
{
    vector<int> num = {1, 1, 3, 4, 7};
    canPartition(num);
    num = vector<int>{15, 13};
    canPartition(num);
}