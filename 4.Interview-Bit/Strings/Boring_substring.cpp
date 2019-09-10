int Solution::solve(string A)
{
    vector<char> hash(26, 0);
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        hash[A[i] - 'a']++;
    }
    for (int i = 0; i < 26; i += 2)
    {
        if (hash[i])
            for (int j = 1; j < 26; j += 2)
            {
                if (hash[j] && abs(i - j) != 1)
                    return 1;
            }
    }
    return 0;
}
