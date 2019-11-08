void LC(vector<string> &ans, vector<string> pc, string A, int i, string t)
{
    if (i == A.size())
    {
        ans.push_back(t);
        return;
    }
    string candi = pc[A[i] - '0'];
    for (int j = 0; j < candi.size(); j++)
    {
        LC(ans, pc, A, i + 1, t + candi[j]);
    }
    return;
}
vector<string> Solution::letterCombinations(string A)
{
    vector<string> pc = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    LC(ans, pc, A, 0, "");
    return ans;
}
