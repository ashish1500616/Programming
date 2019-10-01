#define w(n) cout << (#n) << "\tis\t" << n << "\n"
vector<vector<int>> Solution::solve(vector<int> &A, vector<vector<int>> &B)
{
    int n = A.size();
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + A[i];
    }
    vector<vector<int>> ans;
    for (auto x : B)
    {
        int no = x[1] - x[0] + 1;
        int no1s = ps[x[1]] - ps[x[0] - 1];
        // w(no1s);
        int no0s = no - no1s;
        int res = (no1s & 1 && no1s != 0) ? 1 : 0;
        vector<int> sa = {res, no0s};
        ans.emplace_back(sa);
    }
    return ans;
}
