// Time Complexity O(m*n)

#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;
int LCSRecursion(string A, string B, int i, int j)
{
    // cout<<i<<" "<<j<<"\n";
    if (A[i] == '\0' || B[j] == '\0')
        return 0;
    if (A[i] == B[j])
        return (1 + LCSRecursion(A, B, i + 1, j + 1));
    else
        return (max(LCSRecursion(A, B, i + 1, j), LCSRecursion(A, B, i, j + 1)));
}

pair<vector<char>, int> LCSDynammic(string A, string B)
{
    int la = A.size();
    int lb = B.size();
    int ans = INT_MIN;
    vector<vector<int>> Matrix(la + 1, vector<int>(lb + 1, 0));
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                Matrix[i][j] = Matrix[i - 1][j - 1] + 1;
            }
            else
            {
                Matrix[i][j] = max(Matrix[i][j - 1], Matrix[i - 1][j]);
            }
            ans = max(ans, Matrix[i][j]);
        }
    }
    // Print The Matrix

    // for (auto it1:Matrix)
    // {
    //     for (auto it2:it1)
    //     cout<< it2<< " ";
    //     cout<<"\n";
    // }

    //Find The Subsequence
    int sss = ans - 1;
    vector<char> subseq(ans);
    int i = la, j = lb;
    while (i > 0 && j > 0 && Matrix[i][j] != 0)
    {
        while (Matrix[i][j] == Matrix[i][j - 1])
        {
            j--;
        }
        subseq[sss--] = B[j-1];
        while (Matrix[i][j] == Matrix[i-1][j])
        {
            i--;
        }
        i--;
        j--;
    }
    return {subseq, ans};
}

int solve(string A, string B)
{
    pair<vector<char>, int> ans = LCSDynammic(A, B);
    cout << "Length Of Longest Common Subsequence = " << ans.second << "\n";
    cout << "Longest Common Subsequence = " ;
    for (auto it : ans.first)
    {
        cout << it << " ";
    }
}

int main()
{
    string A{"abbcdgf"};
    string B{"bbadcgf"};
    solve(A, B);
    cout<<"\n";
    return 0;
}