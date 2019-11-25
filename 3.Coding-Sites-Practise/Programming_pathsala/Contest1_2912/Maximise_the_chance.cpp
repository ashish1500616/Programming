#include <bits/stdc++.h>
using namespace std;

void permute(vector<vector<int>> &p, vector<int> &a, int i)
{
    if (i == a.size())
    {
        p.push_back(a);
    }
    for (int j = i; j < a.size(); j++)
    {
        swap(a[j], a[i]);
        permute(p, a, i + 1);
        swap(a[j], a[i]);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> a = {0, 1, 2, 3, 4};
    vector<vector<int>> perm;
    permute(perm, a, 0);
    vector<vector<int>> m(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> m[i][j];
        }
    }
    int ans = INT_MIN;
    for (auto x : perm)
    {
        int sum = 0;
        for (int i = 0; i < 4; i += 1)
        {
            for (int j = i; j < 5; j += 2)
            {
                if (j + 1 < 5)
                {
                    sum += (m[x[j]][x[j + 1]] + m[x[j + 1]][x[j]]);
                }
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}
