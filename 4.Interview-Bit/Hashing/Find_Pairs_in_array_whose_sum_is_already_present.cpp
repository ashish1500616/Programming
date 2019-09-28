int Solution::solve(vector<int> &A)
{
    int n = A.size();
    long long count = 0;
    unordered_set<int> S(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int aj = A[i] + A[j];
            if (S.find(aj) != S.end())
                count++;
        }
    }
    return count;
}
