#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int ans = any_of(a.begin(), a.begin() + 6, [](int x) {
        return x < 0;
    });
    cout << ans << endl;
    return 0;
}