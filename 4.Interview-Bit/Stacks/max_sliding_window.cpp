#define pii pair<int, int>
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B)
{
    int n = A.size();
    priority_queue<pii> max_q;
    vector<int> ans;
    for (int i = 0; i < B; i++)
    {
        max_q.push({A[i], i});
    }
    ans.push_back(max_q.top().first);
    for (int i = B; i < n; i++)
    {
        max_q.push({A[i], i});
        while (max_q.top().second <= i - B)
            max_q.pop();
        ans.push_back(max_q.top().first);
    }
    return ans;
}
int main()
{
    vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int B = 1;
    vector<int> ans = slidingMaximum(A, B);
    for (auto x : ans)
    {
        cout << x << "\n";
    }
    return 0;
}


