void ss(vector<int> &A, vector<vector<int>> &ans, vector<int> &subs, int index)
{
    map<int, int> mp;
    ans.push_back(subs);
    for (int i = index; i < int(A.size()); i++)
    {
        if (mp.count(A[i]) != 0)
            continue;
        mp.insert({A[i], 1});
        subs.push_back(A[i]);
        ss(A, ans, subs, i + 1);
        subs.pop_back();
    }
    return;
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A)
{
    set<int> sa(A.begin(), A.end());
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    // Backtracking Approach
    vector<int> subs;
    ss(A, ans, subs, 0);
    return ans;
}
