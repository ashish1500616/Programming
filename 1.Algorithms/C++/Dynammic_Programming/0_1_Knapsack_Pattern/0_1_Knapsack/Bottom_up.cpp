#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int c = 7;
    vector<vector<int>> dp(profits.size(), vector<int>(c + 1));
    for (int i = 0; i < profits.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= c; j++)
    {
        if (weights[0] <= j)
        {
            dp[0][j] = profits[0];
        }
    }
    for (int i = 1; i < profits.size(); i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int profit_with_including = 0, profit_exluding_current_item = 0;
            // include the item, if it is not more than the capacity
            if (weights[i] <= j)
            {
                // cout << "Weight :" << weights[i] << " "
                //  << "Capacity : " << j << " Therefore  " << profits[i] << " + " << dp[i - 1][j - weights[i]] << "\n";
                profit_with_including = profits[i] + dp[i - 1][j - weights[i]];
            }
            // exclude the item
            profit_exluding_current_item = dp[i - 1][j];
            // take maximum
            dp[i][j] = max(profit_with_including, profit_exluding_current_item);
        }
    }
    for (auto x : dp)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "Max Profit: " << dp[profits.size() - 1][c] << "\n";
    return 0;
}