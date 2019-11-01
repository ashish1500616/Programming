#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> num = {1, 2, 3};
    int n = num.size();
    int op = 1 << n;
    for (int i = 1; i < op; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                // cout << i << " " << (1 << j )<< "\n";
                cout << num[j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}