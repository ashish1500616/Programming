ss(vector<int> &A, vector<vector<int>> &ans, vector<int> &subs, int index, int k)
{
    if (index >= A.size() || accumulate(subs.begin(), subs.end(), 1ll * 0) == k)
    {
        if (accumulate(subs.begin(), subs.end(), 1ll * 0) == k)
        {
            if (!ans.empty() && ans.back() == subs)
                return;
            ans.push_back(subs);
        }
        return;
    }
    // for (int i = index; i < int(A.size()); i++)
    // {
    ss(A, ans, subs, index + 1, k);
    subs.push_back(A[index]);
    ss(A, ans, subs, index + 1, k);
    subs.pop_back();
    // }
    return;
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    // Backtracking Approach
    vector<int> subs;
    ss(A, ans, subs, 0, B);
    return ans;
}