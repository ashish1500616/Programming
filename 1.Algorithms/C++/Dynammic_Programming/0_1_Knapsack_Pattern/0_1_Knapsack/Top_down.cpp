#include <bits/stdc++.h>
using namespace std;

int knapsack_recursion(vector<vector<int>> &dp, vector<int> p, vector<int> w, int c, int i)
{
    if (c <= 0 || i >= w.size())
    {
        return 0;
    }
    if (dp[i][c] != -1)
    {
        return dp[i][c];
    }
    int profit_including_current_item = 0;
    if (w[i] <= c)
        profit_including_current_item = p[i] + knapsack_recursion(dp, p, w, c - w[i], i + 1);
    int profit_excluding_current_item = knapsack_recursion(dp, p, w, c, i + 1);

    dp[i][c] = max(profit_including_current_item, profit_excluding_current_item);
    return dp[i][c];
}
int main()
{
    vector<int> p = {1, 6, 10, 16};
    vector<int> w = {1, 2, 3, 5};
    int c = 7;
    vector<vector<int>> M(p.size(), vector<int>(c+1, -1));
    int max_value = knapsack_recursion(M, p, w, c, 0);
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[0].size(); j++)
        {
            cout << M[i][j] << " \n"[j == M[0].size() - 1];
        }
    }
    cout << max_value << "\n";
    return 0;
}