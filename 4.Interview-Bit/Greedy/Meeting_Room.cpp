int Solution::solve(vector<vector<int>> &A)
{
    vector<int> start;
    vector<int> end;
    for (auto x : A)
    {
        start.push_back(x[0]);
        end.push_back(x[1]);
    }
    sort(start.begin(), start.end());

    sort(end.begin(), end.end());
    int i = 0, j = 0;
    int max_con = INT_MIN, n_con = 0;
    int n = A.size();
    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            i += 1;
            n_con += 1;
            max_con = max(max_con, n_con);
        }
        else
        {
            n_con -= 1;
            j += 1;
        }
    }
    return max_con;
}
