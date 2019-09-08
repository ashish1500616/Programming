#include <bits/stdc++.h>
using namespace std;
// N log N solution
int longestConsecutive(const vector<int> &A)
{

    int l = A.size();
    vector<int> a(A);
    if (l == 1)
        return l;
    map<int, int> m;
    for (auto x : A)
    {
        m[x] = 1;
    }
    int c = 1;
    auto m_t = m.begin();
    int ma = max(m_t->first, INT_MIN);
    for (auto i = (++m.begin()); i != m.end(); i++)
    {
        cout << "mt" << m_t->first << "\n";
        cout << i->first << "\n";
        if ((i->first) - (m_t->first) == 1)
        {
            c += 1;
            ma = max(c, ma);
            cout << "count" << c << "\n";
        }
        else
        {
            c = 1;
            cout << "count" << c << "\n";
        }
        m_t++;
    }
    return ma;
}

// O( N )  Solution
int Solution::longestConsecutive(const vector<int> &A)
{
    unordered_set<int> s;
    for (auto i : A)
    {
        s.insert(i);
    }
    int c_s = 0;
    int m_c = INT_MIN;
    for (auto i : s)
    {
        if (s.find(i - 1) == s.end())
        {
            while (s.find(i++) != s.end())
                c_s++;
        }
        m_c = max(m_c, c_s);
        c_s = 0;
    }
    return m_c;
}

int main()
{
    vector<int> A = {97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81, 7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11, 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95, 94, 56, 28, 55, 66, 92, 79, 27, 42, 70};
    cout << longestConsecutive(A) << "\n";
    return 0;
}