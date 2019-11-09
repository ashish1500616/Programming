class Solution
{
public:
    // [1,2,3,4,5,6,7,8,9]
    //                     k=3,    n=7.
    void helper(vector<int> &n, vector<vector<int>> &ans, vector<int> &s, int i, int k, int sum)
    {
        if (i == n.size() || k == 0)
        {
            if (sum == 0 && k == 0)
            {
                ans.push_back(s);
            }
            return;
        }
        for (int j = i; j < n.size(); j++)
        {
            if (n[j] > sum)
            {
                break;
            }
            s.push_back(n[j]);
            helper(n, ans, s, j + 1, k - 1, sum - n[j]);
            s.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ps;
        vector<int> sub;
        helper(num, ps, sub, 0, k, n);
        return ps;
    }
};