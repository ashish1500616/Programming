#include<bits/stdc++.h>
using namespace std;

// Dynammic Approach Exceeds Memory limit on Interviewbit
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
    cout<< A.substr(ai,bi-ai+1);
}
int main()
{
    longestPalindrome("abbcccbbbcaaccbababcbcabca");
    return 0;
}