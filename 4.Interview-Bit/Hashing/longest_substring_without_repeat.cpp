#define w(n) cout << #n << n << "\n"
int Solution::lengthOfLongestSubstring(string A)
{
    map<char, int> m;
    int ans = INT_MIN;
    int n = A.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(A[i]) == m.end())
        {
            m.insert({A[i], i});
            c++;
            ans = max(c, ans);
        }
        else
        {
            c = 0;
            i = m[A[i]];
            m.clear();
        }
    }
    return ans;
}
