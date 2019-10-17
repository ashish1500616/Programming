#define pii pair<int, int>
#define ps second
#define pf first
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    set<pair<int, pii>> s;
    int na = A.size();
    int nb = B.size();
    priority_queue<pair<int, pii>> hp;
    hp.push({A[0] + B[0], {0, 0}});
    s.insert(hp.top());
    vector<int> ans;
    while (ans.size() != na)
    {
        pair<int, pii> top = hp.top();
        hp.pop();
        ans.push_back(top.pf);
        if ((top.ps.pf + 1 < na) && s.find({A[top.ps.pf + 1] + B[top.ps.ps], {top.ps.pf + 1, top.ps.ps}}) == s.end())
        {
            hp.push({A[top.ps.pf + 1] + B[top.ps.ps], {top.ps.pf + 1, top.ps.ps}});
            s.insert({A[top.ps.pf + 1] + B[top.ps.ps], {top.ps.pf + 1, top.ps.ps}});
        }
        if ((top.ps.ps + 1 < na) && s.find({A[top.ps.pf] + B[top.ps.ps + 1], {top.ps.pf, top.ps.ps + 1}}) == s.end())
        {
            hp.push({A[top.ps.pf] + B[top.ps.ps + 1], {top.ps.pf, top.ps.ps + 1}});
            s.insert({A[top.ps.pf] + B[top.ps.ps + 1], {top.ps.pf, top.ps.ps + 1}});
        }
    }
    return ans;
}
