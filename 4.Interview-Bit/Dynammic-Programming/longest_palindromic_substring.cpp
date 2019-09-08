#include <bits/stdc++.h>
using namespace std;

// Dynammic Approach Exceeds Memory limit on Interviewbit
// Time complexity: O ( n^2 )
// Auxiliary Space: O ( n^2 )
void longestPalindrome(string A)
{
    int n = A.size();
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        M[i][i] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; (j + i) < A.size(); j++)
        {
            if (i == 1)
            {
                M[j][j + i] = (A[j] == A[j + i]) ? 1 : 0;
            }
            else
            {
                if (A[j] == A[j + i] && M[j + 1][j + i - 1])
                {
                    M[j][j + i] = 1;
                }
            }
        }
    }
    for (auto x : M)
    {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
    int ai, bi;
    int m = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = A.size() - 1; j >= i; j--)
        {
            if (M[i][j] == 1)
            {
                //    cout<<i << " " <<j <<" \n";
                if ((j - i + 1) > m)
                {
                    m = j - i + 1;
                    ai = i;
                    bi = j;
                }
            }
        }
    }
    // cout<<ai<<" "<<bi<<"\n";
    cout << A.substr(ai, bi - ai + 1);
}

// T c - O (N^2)
// S C - O (1)

void longestPalindrome(string A)
{
    int n = A.size();
    int ml = 1;
    int s, e;
    for (int i = 1; i < n; i++)
    {
        int l = i - 1;
        int h = i + 1;
        while (l >= 0 && h < n && A[l] == A[h])
        {
            if (h - l + 1 > ml)
            {
                s = l;
                ml = h - l + 1;
            }
            --l;
            h++;
        }
        l = i - 1;
        h = i;
        while (l >= 0 && h < n && A[l] == A[h])
        {
            if (h - l + 1 > ml)
            {
                s = l;
                ml = h - l + 1;
            }
            --l;
            h++;
        }
    }
    cout << A.substr(s, ml);
}

int main()
{
    longestPalindrome("");
    return 0;
}