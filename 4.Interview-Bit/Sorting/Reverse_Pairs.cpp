void merge_sort(vector<pair<int, int>>::iterator begin, vector<pair<int, int>>::iterator end, vector<int> &ret)
{
    if (end - begin <= 1)
        return;
    auto mid = begin + (end - begin) / 2;
    merge_sort(begin, mid, ret);
    merge_sort(mid, end, ret);
    auto r = mid;
    for (auto l = begin; l != mid; l++)
    { // combine
        while (r != end && l->first > 2 * r->first)
            r++;
        ret[l->second] += r - mid;
    }
    inplace_merge(begin, mid, end); // inplace merge
}

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    vector<pair<int, int>> ps;
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++)
        ps.push_back({A[i], i});
    merge_sort(ps.begin(), ps.end(), ret);
    int sum = accumulate(ret.begin(), ret.end(), 0);
    return sum;
}