// Concept : - Sliding Window + Hashing.
string Solution::minWindow(string A, string B)
{
    unordered_map<char, int> m;
    string ans = "";
    for (auto x : B)
    {
        if (m.count(x) == 0)
        {
            m.insert({x, 1});
        }
        else
        {
            ++m[x];
        }
    }
    int begin = 0;
    int end = 0;
    int len = INT_MAX;
    int distinctCharacters = m.size();
    while (end < A.size())
    {
        char endChar = A[end];
        if (m.count(endChar) != 0)
        {
            m[endChar] -= 1;
            if (m[endChar] == 0)
            {
                --distinctCharacters;
            }
        }
        ++end;
        while (distinctCharacters == 0)
        {
            if (end - begin < len)
            {
                len = end - begin;
                ans = A.substr(begin, end - begin);
            }
            char startChar = A[begin];
            if (m.count(startChar) != 0)
            {
                ++m[startChar];
                if (m[startChar] > 0)
                {
                    ++distinctCharacters;
                }
            }
            ++begin;
        }
    }
    return ans;
}
