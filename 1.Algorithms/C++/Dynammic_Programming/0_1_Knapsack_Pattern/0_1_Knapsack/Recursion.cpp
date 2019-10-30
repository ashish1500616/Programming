#include <bits/stdc++.h>
using namespace std;

int knapsack_recursion(vector<int> p, vector<int> w, int c, int i)
{
    if (c <= 0 || i >= w.size())
    {
        return 0;
    }
    int profit_including_current_item = 0;
    if (w[i] <= c)
        profit_including_current_item = p[i] + knapsack_recursion(p, w, c - w[i], i + 1);
    int profit_excluding_current_item = knapsack_recursion(p, w, c, i + 1);

    return max(profit_including_current_item, profit_excluding_current_item);
}
int main()
{
    vector<int> p = {1, 6, 10, 16};
    vector<int> w = {1, 2, 3, 5};
    int c = 7;

    int max_profit = knapsack_recursion(p, w, c, 0);
    cout << max_profit << "\n";
    return 0;
}