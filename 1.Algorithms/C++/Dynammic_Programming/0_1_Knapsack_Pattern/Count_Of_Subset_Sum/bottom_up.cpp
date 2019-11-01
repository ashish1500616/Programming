#include<bits/stdc++.h>
using namespace std;

int countSubsetSum()

int main()
{
    vector<int> v = {1, 10, 2, 8, 15, 4};
    int ans = countSubsetSum(v, 0, 12);
    cout << ans << "\n";
    return ans;
}